#include "TerrainPool.h"

namespace Stone
{
	void TerrainPool::getTerrain(const TerrainQuadTree::Node& node, std::vector<NoiseTerrain*>& target)
	{
		char buffer[512];
		sprintf(buffer, "<min<%f_%f>_max<%f_%f>>", node.bondsMin.x, node.bondsMin.z, node.bondsMax.x, node.bondsMax.z);
		if (m_TerrainPool.find(buffer) != m_TerrainPool.end())
		{
			target.push_back(m_TerrainPool[buffer]);
		}
		else
		{
			m_TerrainPool[buffer] = new NoiseTerrain(12345, node);
			target.push_back(m_TerrainPool[buffer]);
		}
	}
}