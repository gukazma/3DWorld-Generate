#pragma once
#include <Resource/Data/Implement/VCG/VCGMesh.h>
#include <vector>
namespace Stone
{
	class NoiseTerrain : public VCGMesh
	{
	public:
		NoiseTerrain(uint32_t seed, uint32_t width, uint32_t height, uint32_t heightmax = 10);
	private:
		std::vector<std::vector<float>> m_HeightMap;
	};
}