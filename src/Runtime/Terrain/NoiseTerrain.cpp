#include "NoiseTerrain.h"
#include <PerlinNoise.hpp>
#include <glm/glm.hpp>

#include<vcg/complex/algorithms/create/platonic.h>
namespace Stone
{
	NoiseTerrain::NoiseTerrain(uint32_t seed, uint32_t width, uint32_t height)
	{
		m_HeightMap = std::vector<std::vector<float>>(width, std::vector<float>(height, 0));

        std::vector<vcg::Point3f> vertices;
        std::vector<vcg::Point3i> indices;

		//const siv::PerlinNoise perlin{ seed };
		//for (size_t x = 0; x < width; x++)
		//{
		//	for (size_t y = 0; y < height; y++)
		//	{
		//		m_HeightMap[x][y] = perlin.octave2D_01((x * 0.01), (y * 0.01), 4);
		//	}
		//}

  //      for (int i = 0; i < width - 1; i++)
  //      {
  //          for (int j = 0; j < height - 1; j++)
  //          {

  //              float UL = (float)(m_HeightMap[i][j]); // Upper left

  //              float LL = (float)(m_HeightMap[i + 1][j]); // Lower left
  //              float UR = (float)(m_HeightMap[i][j + 1]); // Upper right
  //              float LR = (float)(m_HeightMap[i + 1][j + 1]); // Lower right

  //              glm::vec3 ULV = { i , UL, j };
  //              glm::vec3 LLV = { i, LL, j };
  //              glm::vec3 URV = { i, UR, j + 1 };
  //              glm::vec3 LRV = { i + 1, LR, j + 1 };

  //              vertices.push_back(vcg::Point3f(ULV.x, ULV.y, ULV.z));
  //              vertices.push_back(vcg::Point3f(LLV.x, LLV.y, LLV.z));
  //              vertices.push_back(vcg::Point3f(URV.x, URV.y, URV.z));
  //              vertices.push_back(vcg::Point3f(LRV.x, LRV.y, LRV.z));
  //              indices.push_back(vcg::Point3i(vertices.size() - 4, vertices.size() - 1, vertices.size() - 2));
  //              indices.push_back(vcg::Point3i(vertices.size() - 4, vertices.size() - 3, vertices.size() - 1));
  //          }
  //      }
        vertices.push_back(vcg::Point3f(-0.5, -0.5, 0.0));
        vertices.push_back(vcg::Point3f(-0.5, 0.5, 0.0));
        vertices.push_back(vcg::Point3f(0.5, 0.5, 0.0));
        vertices.push_back(vcg::Point3f(0.5, -0.5, 0.0));
        indices.push_back(vcg::Point3i(vertices.size() - 4, vertices.size() - 1, vertices.size() - 2));
        indices.push_back(vcg::Point3i(vertices.size() - 4, vertices.size() - 3, vertices.size() - 1));

        vcg::tri::BuildMeshFromCoordVectorIndexVector(m_Mesh, vertices, indices);

        update();

		updateBuffer();
	}
}