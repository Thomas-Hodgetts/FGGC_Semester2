#include "CameraFlotilla.h"

void CameraFlotilla::AddObject(Camera* c)
{
	m_Cameras.push_back(c);
}

void CameraFlotilla::Update()
{
	for (auto cameras : m_Cameras)
	{
		cameras->Update();
	}
}
void CameraFlotilla::ClearObjects()
{
	for (auto cameras : m_Cameras)
	{
		delete cameras;
	}
	m_Cameras.clear();
}

Camera* CameraFlotilla::ReturnCamera(int Placement)
{
	return m_Cameras[Placement];
}

Camera* CameraFlotilla::ReturnCamera(std::string name)
{
	for (auto cameras : m_Cameras)
	{
		if (name == cameras->GetName())
		{
			return cameras;
		}
	}
}


int CameraFlotilla::ReturnVectorSize()
{
	return m_Cameras.size();
}