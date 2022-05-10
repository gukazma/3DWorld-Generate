#include "TerrainManager.h"
#include "TerrainQuadTree.h"

#include <Core/Log/LogSystem.h>
namespace Stone
{
	void TerrainManager::getTerrain(glm::vec3 camerapos, std::vector<NoiseTerrain*>& target, glm::vec3 min, glm::vec3 max)
	{
		TerrainQuadTree tree(min, max);
		tree.insert(camerapos);

		std::vector<TerrainQuadTree::Node> terrainTarget;
		tree.getLeavesNode(terrainTarget);
		size_t count = 0;
		for (auto t : terrainTarget)
		{
			target.push_back(new NoiseTerrain(123456, t));
		}
	}
}
