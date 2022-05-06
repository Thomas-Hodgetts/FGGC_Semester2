#pragma once
#include <vector>
#include <algorithm>
#include "TerrainVertex.h"


class TerrainArray
{ 
public:
	TerrainArray();
	~TerrainArray();

	//Methods

	//Inserts a simple vertex at the point the Vertex specifies
	void Insert(TerrainVertex v);
	//Removes a vertex and sets its point as null
	void Remove(TerrainVertex v);
	//Removes a vertex and sets its point as null
	void Remove(int x, int y);
	//Removes a vertex and sets its point as null, then moves everything down an index
	void RemoveAndReplace();
	//Removes a vertex and sets its point as null, then adds a new vertex
	void RemoveAndReplace(TerrainVertex v);
	//Replaces a point in the list
	void Replace(TerrainVertex v);

	void InsertIndex(Vector3D Index);

	std::vector<TerrainVertex*> ReturnVertex() { return m_Terrain; };
	std::vector<Vector3D*> ReturnIndices() { return m_Indicies; };

	ID3D11Buffer* GenerateVertexBuffer();
	ID3D11Buffer* GenerateIndexBuffer();

private: 

	Debug d;

	Vector3D m_PreviousEye;
	std::vector<TerrainVertex*> m_Terrain;
	std::vector<Vector3D*> m_Indicies;

	ID3D11Buffer* TerrainVertexBuffer;
	ID3D11Buffer* TerrainIndexBuffer;
};

