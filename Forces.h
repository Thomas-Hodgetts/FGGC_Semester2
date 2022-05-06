#pragma once
#include "Vector3D.h"


class Forces
{
public:
	//Default Update
	virtual Vector3D* Update(Vector3D* netforce);
	//Gravity's Update
	virtual Vector3D* Update(Vector3D* netforce, float Mass, float OpposingMass, Vector3D* Distance);
	void SetObjectMass(float om) { m_ObjectMass = om; };
	std::string m_Type;
protected:
	float m_ObjectMass;
};

