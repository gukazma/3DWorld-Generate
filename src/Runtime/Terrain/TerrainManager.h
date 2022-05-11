#pragma once
#include <Core/Base/PublicSingleton.h>
#include <glm/glm.hpp>
#include "NoiseTerrain.h"
#include <vector>
namespace Stone
{
	class TerrainManager : public PublicSingleton<TerrainManager>
	{
	public:
		void getTerrain(const glm::vec3& camerapos, std::vector<NoiseTerrain*>& target, glm::vec3 min, glm::vec3 max);
		
	};
}