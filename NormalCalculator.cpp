#include "NormalCalculator.h"

XMFLOAT3 NormalCalculator::CrossProductCalculation(XMFLOAT3 Vertex1, XMFLOAT3 Vertex2, XMFLOAT3 Vertex3)
{
	XMVECTOR U = XMVectorSubtract(XMLoadFloat3(&Vertex2), XMLoadFloat3(&Vertex1));
	XMVECTOR V = XMVectorSubtract(XMLoadFloat3(&Vertex3), XMLoadFloat3(&Vertex1));
	XMVECTOR Cross = XMVector3Cross(U, V);
	XMStoreFloat3(&FinalCrossProduct, XMVector3Normalize(Cross));
	return FinalCrossProduct;
}

Vector3D NormalCalculator::CrossProductCalculation(Vector3D Vertex1, Vector3D Vertex2, Vector3D Vertex3)
{
	XMVECTOR U = XMVectorSubtract(XMLoadFloat3(&Vertex2.ConvertToXMfloat3()), XMLoadFloat3(&Vertex1.ConvertToXMfloat3()));
	XMVECTOR V = XMVectorSubtract(XMLoadFloat3(&Vertex3.ConvertToXMfloat3()), XMLoadFloat3(&Vertex1.ConvertToXMfloat3()));
	XMVECTOR Cross = XMVector3Cross(U, V);
	XMStoreFloat3(&FinalCrossProduct, XMVector3Normalize(Cross));
	return FinalCrossProduct;
}

XMFLOAT3 NormalCalculator::CalculateAverageWithVector(std::vector<XMFLOAT3> CrossList)
{
	XMFLOAT3 Average = { 0,0,0 };
	for (int i = 0; i < CrossList.size(); i++)
	{
		Average.x += CrossList[i].x;
		Average.y += CrossList[i].y;
		Average.z += CrossList[i].z;
	}

	Average.x /= CrossList.size();
	Average.y /= CrossList.size();
	Average.z /= CrossList.size();
	return Average;
}

Vector3D NormalCalculator::CalculateAverageWithVector(std::vector<Vector3D> CrossList)
{
	XMFLOAT3 Average = { 0,0,0 };
	for (int i = 0; i < CrossList.size(); i++)
	{
		Average.x += CrossList[i].ReturnX();
		Average.y += CrossList[i].ReturnY();
		Average.z += CrossList[i].ReturnZ();
	}

	Average.x /= CrossList.size();
	Average.y /= CrossList.size();
	Average.z /= CrossList.size();
	return Average;
}

void NormalCalculator::NormalResult(std::vector<TerrainVertex*> TV, std::vector<Vector3D*> Indices)
{
	std::vector<Vector3D> CPC;
	Vector3D globalAverage;
	for each (Vector3D* index in Indices)
	{
		CPC.push_back(CrossProductCalculation(TV[index->ReturnX()]->Pos, TV[index->ReturnY()]->Pos, TV[index->ReturnZ()]->Pos));
	}

	globalAverage = CalculateAverageWithVector(CPC);

	for each (TerrainVertex * tv in TV)
	{
		tv->Normal = globalAverage.ConvertToXMfloat3();
	}
}
