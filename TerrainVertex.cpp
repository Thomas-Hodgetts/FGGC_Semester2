#include "TerrainVertex.h"

TerrainVertex::TerrainVertex(SimpleVertex sv)
{

}
TerrainVertex::TerrainVertex()
{

}

TerrainVertex::~TerrainVertex()
{

}

void TerrainVertex::CalculateDistFromCam(Vector3D* eye)
{
	float diffX = Pos.x - eye->ReturnX();
	float diffY = Pos.y - eye->ReturnY();;
	float diffZ = Pos.z - eye->ReturnZ();;
	float diff = (diffX + diffY + diffZ) / 3;
	AverageDistFromCams = diff;
}