#include "Terrain.h"


Terrain::Terrain()
{
	m_Terrain = new TerrainArray();
}

Terrain::~Terrain()
{
	delete m_Terrain;
}

Terrain::Terrain(int x, int z, std::string MapLocale, float scale, ID3D11Device* device, std::string TexLocale)
{
	m_HeightMapScale = scale;
	Loader L;
	NormalCalculator n;
	std::vector<float> HieghtMap = L.LoadTerrainMapFromFile(MapLocale, x , z, m_HeightMapScale);
	m_TextureStore = L.LoadMuiltipleTerrainTexFromFile(device,"/Resources/Scene.json");
	std::vector<ID3D11ShaderResourceView*> m_Textures;
	m_Terrain = new TerrainArray();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < z; j++)
		{
			TerrainVertex s;
			s.Pos.x = ((-0.5f * x) + (j * 1));
			s.Pos.y = HieghtMap[i+j];
			s.Pos.z = ((0.5 * z) - (i * 1));
			m_Terrain->Insert(s);
			m_Terrain->InsertIndex(Vector3D( i * x + j, i * x + j + 1 , (i + 1) * x + j));
			m_Terrain->InsertIndex(Vector3D((i + 1) * x + j , i * x + j + 1, (i + 1) * x + j + 1));
		}
	}
	n.NormalResult(m_Terrain->ReturnVertex(), m_Terrain->ReturnIndices());

}

void Terrain::Draw(ID3D11DeviceContext* device)
{

}