#pragma once
# include "Camera.h"
#include <vector>

//A flotilla is a group of objects with similar resource needs and are used to be batch rendered or just stored. This version is for CAMERAS
class CameraFlotilla
{
public:

	//Adds a camera to the list of cameras
	void AddObject(Camera* c);
	//Clears the flotillas
	void ClearObjects();
	//Updates the cameras
	void Update();
	//Returns a specified object
	Camera* ReturnCamera(int Placement);
	//Returns a specified object
	Camera* ReturnCamera(std::string name);
	//Returns the Size of the local vector
	int ReturnVectorSize();

private:

	std::vector<Camera*> m_Cameras;

};

