#pragma once
#include <Core/Base/PublicSingleton.h>
#include <map>
#include <string>
#include "NoiseTerrain.h"

#include "TerrainQuadTree.h"
namespace Stone
{
	class TerrainPool : PublicSingleton<TerrainPool>
	{
	public:
		void getTerrain(const TerrainQuadTree::Node& node, std::vector<NoiseTerrain*>& target);
	private:
		std::map<std::string, NoiseTerrain*> m_TerrainPool; 
	};
}