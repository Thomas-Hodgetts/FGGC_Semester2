#pragma once
#include "Vector3D.h"
#include "ParticleModel.h"
#include <Vector>
#include <map>
#include <cstdlib>

class ParticleSystem
{
	public:

		ParticleSystem();
		~ParticleSystem();

		void Update(float deltaTime);
		void Draw(ID3D11DeviceContext* device);
		void CreateParticle(int amount, Particle* particle);
		//Removes a specified particle group from the system
		void RemoveParticleGroup(int Position);
		//Removes a specified particle group from the system
		void RemoveParticleGroup(Particle* Position);
		//Allows you to make changes to the force
		void AddforceToParticle(Particle* particle);
		//Returns all the particles stored in this system
		std::vector<std::vector<Particle*>> ReturnAllParticles() { return m_ParticleStorage; };


	private:
		std::vector<std::vector<Particle*>> m_ParticleStorage;
	
};

