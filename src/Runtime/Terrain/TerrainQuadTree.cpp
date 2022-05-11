#include "TerrainQuadTree.h"
#include <iostream>
namespace Stone
{
#define MIN_NODE_SIZE 40
	TerrainQuadTree::TerrainQuadTree(const glm::vec3& min, const glm::vec3& max)
	{
		m_Root.bondsMin = min;
		m_Root.bondsMax = max;
		m_Root.updateBox();
	}

	void TerrainQuadTree::insert(const glm::vec3& pos)
	{
		insert(m_Root, pos);
	}

	void TerrainQuadTree::getLeavesNode(Node& child, std::vector<Node>& target)
	{
		if (child.children.size() == 0)
		{
			target.push_back(child);
		}
		else
		{
			for (auto c : child.children)
			{
				getLeavesNode(c, target);
			}
		}
	}

	void TerrainQuadTree::insert(Node& child, const glm::vec3& pos)
	{
		float distanceToChild = glm::dot(child.center - pos, child.center - pos);

		if (distanceToChild < child.size.x * child.size.x && child.size.x > MIN_NODE_SIZE)
		{
			createChild(child);
			for (auto& c : child.children)
			{
				insert(c, pos);
			}
		}
	}

	void TerrainQuadTree::getLeavesNode(std::vector<Node>& target)
	{
		getLeavesNode(m_Root, target);
	}

	void TerrainQuadTree::createChild(Node& child)
	{
		glm::vec3 center = child.center;

		Node bl;
		bl.bondsMin = child.bondsMin;
		bl.bondsMax = child.center;
		bl.updateBox();

		Node br;
		br.bondsMin = { center.x, 0.0, child.bondsMin.z };
		br.bondsMax = { child.bondsMax.x, 0.0,  center.z };
		br.updateBox();


		Node tl;
		tl.bondsMin = { child.bondsMin.x, 0.0, center.z };
		tl.bondsMax = { center.x, 0.0, child.bondsMax.z };
		tl.updateBox();

		Node tr;
		tr.bondsMin = center;
		tr.bondsMax = child.bondsMax;
		tr.updateBox();

		child.children.push_back(bl);
		child.children.push_back(br);
		child.children.push_back(tl);
		child.children.push_back(tr);
	}
	void TerrainQuadTree::Node::updateBox()
	{
		auto center2 = bondsMax + bondsMin;
		center = { center2.x / 2, center2.y / 2, center2.z / 2 };
		size = { abs(bondsMax.x - bondsMin.x), abs(bondsMax.z - bondsMin.z) };
	}
}