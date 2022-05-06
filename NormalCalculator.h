#pragma once
#include <d3d11_1.h>
#include <directxmath.h>
#include "TerrainVertex.h"
#include <vector>


//Heavily based off the book


using namespace DirectX;

class NormalCalculator
{
private:

	XMFLOAT3 FinalCrossProduct;


	//Calculates the normals for each point using Cross Products and normalisation. Doesn't calculate averages
	XMFLOAT3 CrossProductCalculation(XMFLOAT3 Vertex1, XMFLOAT3 Vertex2, XMFLOAT3 Vertex3);

	//Calculates the normals for each point using Cross Products and normalisation. Doesn't calculate averages
	Vector3D CrossProductCalculation(Vector3D Vertex1, Vector3D Vertex2, Vector3D Vertex3);

	//Calculates Cross Product Averages
	XMFLOAT3 CalculateAverageWithVector(std::vector<XMFLOAT3> CrossList);
	//Calculates Cross Product Averages
	Vector3D CalculateAverageWithVector(std::vector<Vector3D> CrossList);

public:

	//Calculates the average normal for an object
	void NormalResult(std::vector<TerrainVertex*> TV, std::vector<Vector3D*> Indices);

};

