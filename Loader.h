#pragma once
#include "Structures.h"
#include "OBJLoader.h"
#include "DDSTextureLoader.h"
#include "TerrainTex.h"
#include "Debug.h"
#include <fstream>
#include <string>
#include <filesystem>
#include <map>


class Loader
{
public:
	Loader();
	~Loader();

	//
	MeshData LoadMesh(char* filename, ID3D11Device* _pd3dDevice, bool invertTexCoords);
	//Loads and creates a texture from a given file
	ID3D11ShaderResourceView* LoadTex(ID3D11Device* d3dDevice, const wchar_t* fileName);

	//Terrain related load functions

	//This Loads the file containing the data for the height map
	std::vector<float> LoadTerrainMapFromFile(std::string FileLocation, int heightmapWidth, int heightmapHeight, int heightScale);
	//This loads and creates  multiple textures from a given file i.e. a json file
	std::vector<TerrainTex*> LoadMuiltipleTerrainTexFromFile(ID3D11Device* d3dDevice, std::string FileLocation);
};

