#pragma once
#include <glm/glm.hpp>
#include <vector>
namespace Stone
{
	class TerrainQuadTree
	{
	public:
		struct Node
		{
			glm::vec3 bondsMin;
			glm::vec3 bondsMax;
			glm::vec3 center;
			glm::vec2 size;
			std::vector<Node> children;

			void updateBox();
		};
		TerrainQuadTree(const glm::vec3& min, const glm::vec3& max);

		void insert(const glm::vec3& pos);

		void getLeavesNode(std::vector<Node>& target);

	private:

		void getLeavesNode(Node& child, std::vector<Node>& target);
		void insert(Node& child, const glm::vec3& pos);
		void createChild(Node& child);
		Node m_Root;
	};
}