#include "Flotilla.h"

Flotilla::Flotilla()
{
	
}

Flotilla::~Flotilla()
{

}

void Flotilla::AddObject(GameObject* newObject)
{
	m_Objects.push_back(newObject);
}

void Flotilla::ClearObjects()
{
	for (auto gameObject : m_Objects)
	{
		delete gameObject;
	}
	m_Objects.clear();
}

void Flotilla::Update(float deltaTime)
{
	for (auto gameObject : m_Objects)
	{
		gameObject->Update(deltaTime);
	}
}

void Flotilla::Draw(ID3D11DeviceContext* device)
{
	for (auto gameObject : m_Objects)
	{
		gameObject->Draw(device);
	}
}

GameObject* Flotilla::ReturnObject(int Placement)
{
	return m_Objects[Placement];
}

int Flotilla::ReturnVectorSize()
{
	return m_Objects.size();
}
vector<GameObject*> Flotilla::FindAndReturnObject(string name)
{
	vector<GameObject*> s;

	for (auto gameObject : m_Objects)
	{
		if (gameObject->GetType() == name)
		{
			s.push_back(gameObject);
		}
	}
	if (s.size() >= 1)
	{
		return s;
	}
	else
	{
		return s;
	}
}