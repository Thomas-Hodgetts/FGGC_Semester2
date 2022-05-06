#pragma once
#include "Forces.h"

class Gravity : public Forces
{
public:
	Gravity(float ObjectMass);
	~Gravity();
	//Updates the gravity force
	Vector3D* Update(Vector3D* netforce, float Mass, float OpposingMass, Vector3D* Distance);
	//Sets gravity strength
	void SetGravity(float gravstrength) { m_GravityStrength = gravstrength; };
	//returns the gravity's strength
	float ReturnGravityStrength() { return m_GravityStrength; };

private:
	float m_GravityStrength = 9.81;
};

