#pragma once
#include "Structures.h"
#include "GameObject.h"


//A flotilla is a group of objects with similar resource needs and are used to be batch rendered or just stored. This version is for GAMEOBJECTS
class Flotilla
{
public:
	Flotilla();
	~Flotilla();

	//Set Funcs & return fucns

	//Returns if the flotilla is drawable, pass bool to set it
	bool Drawable() { return m_Drawable; }
	//Returns if the flotilla is drawable, pass bool to set it
	void Drawable(bool value) { m_Drawable = value; }


	//Adds an object to the flotilla
	virtual void AddObject(GameObject* newObject);
	//Clears the entire flotilla.
	virtual void ClearObjects();
	//Draws all the objects in the flotilla.
	virtual void Draw(ID3D11DeviceContext* device);
	//Calls the update function of all of the objects in a flotilla leader
	virtual void Update(float deltaTime);
	//Returns a specified object
	virtual GameObject* ReturnObject(int Placement);
	//Returns the Size of the local vector
	int ReturnVectorSize();
	//Finds a gameObject in the flotilla, if there are multiple it will create an array and return that. returns empty array if it fails
	virtual vector<GameObject*> FindAndReturnObject(string name);

protected: 
	//Name of the flotilla
	std::string Name;
private:

	std::vector<GameObject*> m_Objects;
	//For the Flotilla Draw Function
	bool m_Drawable = true;

};