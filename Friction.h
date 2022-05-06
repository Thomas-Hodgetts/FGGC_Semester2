#pragma once
#include "Forces.h"

class Friction : public Forces
{
public:

	Friction();
	Friction(float FrictionIntensity);
	~Friction();
	Vector3D* Update(Vector3D* netforce);

private:
	//The type of force
	std::string type = "Friction";
	//Intensity of friction
	float m_FrictionStrength;
};

