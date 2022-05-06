#pragma once
#include "Structures.h"
#include "Vector3D.h"
class TerrainVertex : public SimpleVertex
{
public:
	TerrainVertex();
	TerrainVertex(SimpleVertex sv);
	~TerrainVertex();
	
	void CalculateDistFromCam(Vector3D* Cam);

	float AverageDistFromCams;

};

