#include "NoiseTerrain.h"
#include <PerlinNoise.hpp>
#include <glm/glm.hpp>

#include<vcg/complex/algorithms/create/platonic.h>
namespace Stone
{
	NoiseTerrain::NoiseTerrain(uint32_t seed, uint32_t bottomwidth, uint32_t bottomheight, uint32_t heightmax)
        : m_MaxHeight(heightmax)
	{
		m_HeightMap = std::vector<std::vector<float>>(bottomwidth, std::vector<float>(bottomheight, 0));

        std::vector<vcg::Point3f> vertices;
        std::vector<vcg::Point3i> indices;

		const siv::PerlinNoise perlin{ seed };
		for (size_t x = 0; x < bottomwidth; x++)
		{
			for (size_t y = 0; y < bottomheight; y++)
			{
				m_HeightMap[x][y] = (2 * perlin.octave2D_01((x * 0.01), (y * 0.01), 4) - 1);
			}
		}

        for (int i = 0; i < bottomwidth - 1; i++)
        {
            for (int j = 0; j < bottomheight - 1; j++)
            {

                float UL = (float)(m_HeightMap[i][j]); // Upper left

                float LL = (float)(m_HeightMap[i + 1][j]); // Lower left
                float UR = (float)(m_HeightMap[i][j + 1]); // Upper right
                float LR = (float)(m_HeightMap[i + 1][j + 1]); // Lower right

                glm::vec3 ULV = { i , UL * m_MaxHeight , j };
                glm::vec3 LLV = { i + 1, LL * m_MaxHeight , j };
                glm::vec3 URV = { i, UR * m_MaxHeight , j + 1 };
                glm::vec3 LRV = { i + 1, LR * m_MaxHeight , j + 1 };

                vertices.push_back(vcg::Point3f(ULV.x, ULV.y, ULV.z));
                vertices.push_back(vcg::Point3f(LLV.x, LLV.y, LLV.z));
                vertices.push_back(vcg::Point3f(URV.x, URV.y, URV.z));
                vertices.push_back(vcg::Point3f(LRV.x, LRV.y, LRV.z));
                indices.push_back(vcg::Point3i(vertices.size() - 4, vertices.size() - 1, vertices.size() - 2));
                indices.push_back(vcg::Point3i(vertices.size() - 4, vertices.size() - 3, vertices.size() - 1));
            }
        }
        /*vertices.push_back(vcg::Point3f(0 ,0 ,0));
        vertices.push_back(vcg::Point3f(10, 0, 0));
        vertices.push_back(vcg::Point3f(0, 0, 10));
        vertices.push_back(vcg::Point3f(10, 0, 10));
        indices.push_back(vcg::Point3i(vertices.size() - 4, vertices.size() - 1, vertices.size() - 2));
        indices.push_back(vcg::Point3i(vertices.size() - 4, vertices.size() - 3, vertices.size() - 1));*/

        vcg::tri::BuildMeshFromCoordVectorIndexVector(m_Mesh, vertices, indices);

        update();
	}
    void NoiseTerrain::setMaxHeight(float maxheight)
    {
        for (auto& v : m_Mesh.vert)
        {
            v.P().Y() = v.P().Y() / m_MaxHeight * maxheight;
        }

        m_MaxHeight = maxheight;
        update();
        updateBuffer();
    }
}