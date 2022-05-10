#pragma once
#include <Resource/Data/Implement/VCG/VCGMesh.h>
#include <vector>
#include <glm/glm.hpp>

#include "TerrainQuadTree.h"
namespace Stone
{
	class NoiseTerrain : public VCGMesh
	{
	public:
		NoiseTerrain(uint32_t seed, uint32_t width, uint32_t height, uint32_t heightmax = 10);

		NoiseTerrain(uint32_t seed, const TerrainQuadTree::Node& node);

		void setMaxHeight(float maxheight);

		float m_MaxHeight = 20;
	private:
		std::vector<std::vector<float>> m_HeightMap;
	};
}