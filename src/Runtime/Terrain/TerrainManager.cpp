#include "TerrainManager.h"
#include "TerrainQuadTree.h"

#include <Core/Log/LogSystem.h>
#include "TerrainPool.h"
namespace Stone
{
	void TerrainManager::getTerrain(const glm::vec3& camerapos, std::vector<NoiseTerrain*>& target, glm::vec3 min, glm::vec3 max)
	{
		target.clear();
		TerrainQuadTree tree(min, max);
		tree.insert(camerapos);

		std::vector<TerrainQuadTree::Node> terrainTarget;
		tree.getLeavesNode(terrainTarget);
		size_t count = 0;
		for (auto t : terrainTarget)
		{
			PublicSingletonInstance(TerrainPool).getTerrain(t, target);
		}
	}
}
