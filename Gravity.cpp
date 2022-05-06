#include "Gravity.h"

Gravity::Gravity(float ObjectMass)
{
	m_Type = "Gravity";
	m_ObjectMass = ObjectMass;
}

Gravity::~Gravity()
{

}

//https://stackoverflow.com/questions/10589559/shortest-way-to-calculate-difference-between-two-numbers


Vector3D* Gravity::Update(Vector3D* netforce, float Mass, float OpposingMass, Vector3D* Distance)
{
	Vector3D localDis = *netforce > *Distance ? *netforce - *Distance : *Distance - *netforce;
	Vector3D finalout = Vector3D(netforce->ReturnX(),Mass * OpposingMass, netforce->ReturnZ());
	*netforce = finalout / (localDis * localDis);
	return netforce;
}