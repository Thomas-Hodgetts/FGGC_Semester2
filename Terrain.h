#pragma once
#include "Vector3D.h"
#include "Loader.h"
#include "TerrainArray.h"
#include "TerrainTex.h"
#include "NormalCalculator.h"
#include <map>

class Terrain 
{
public:
	Terrain();
	Terrain(int x, int z, std::string MapLocale, float scale, ID3D11Device* device, std::string TexLocale);
	~Terrain();

	void AddTexture(TerrainTex* TT);

	void Draw(ID3D11DeviceContext* device);


private:


	Loader m_Loader;
	TerrainArray* m_Terrain;
	std::vector<TerrainTex*> m_TextureStore;
	float m_HeightMapScale;
};

