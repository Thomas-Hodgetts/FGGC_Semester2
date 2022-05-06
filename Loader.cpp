#include "Loader.h"

Loader::Loader()
{

}
Loader::~Loader()
{

}


std::vector<TerrainTex*> Loader::LoadMuiltipleTerrainTexFromFile(ID3D11Device* d3dDevice, std::string FileLocation)
{
	std::vector<TerrainTex*> tex;
	FileLocation = std::filesystem::current_path().string() + FileLocation;

	return std::vector<TerrainTex*>();
}


std::vector<float> Loader::LoadTerrainMapFromFile(std::string FileLocation, int heightmapWidth, int heightmapHeight, int heightScale)
{
	FileLocation = std::filesystem::current_path().string() + FileLocation;
	std::vector<unsigned char> in(heightmapWidth * heightmapHeight);
	std::vector<float> out(heightmapHeight * heightmapWidth, 0);

	std::ifstream inFile;
	inFile.open(FileLocation.c_str(), std::ios_base::binary);

	if (inFile)
	{
		inFile.read((char*)&in[0], (std::streamsize)in.size());
		inFile.close();
	}

	for (UINT i = 0; i < heightmapHeight * heightmapWidth; ++i)
	{
		out[i] = (in[i] / 255.0f) * heightScale;
	}
	return out;

}

ID3D11ShaderResourceView* Loader::LoadTex(ID3D11Device* d3dDevice, const wchar_t* fileName)
{
	ID3D11ShaderResourceView* texture;
	HRESULT hr;
	hr = CreateDDSTextureFromFile(d3dDevice, fileName, nullptr, &texture);
	if (FAILED(hr))
		return nullptr;
	else
	{
		return texture;
	}
}

MeshData Loader::LoadMesh(char* filename, ID3D11Device* _pd3dDevice, bool From3dsMax)
{
	if (From3dsMax)
	{
		return OBJLoader::Load(filename, _pd3dDevice);
	}
	else if (!From3dsMax)
	{
		return OBJLoader::Load(filename, _pd3dDevice, false);
	}
}