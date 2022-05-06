#include "ParticleSystems.h"

ParticleSystem::ParticleSystem()
{

}
ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::CreateParticle(int amount, Particle* particle)
{
	std::vector<Particle*> pa;
	for (int i = 0; i < amount; i++)
	{
		pa[i] = particle;
	}
	m_ParticleStorage.push_back(pa);
}

void ParticleSystem::Update(float deltaTime)
{
	for (auto particle : m_ParticleStorage)
	{
		for (auto particles : particle)
		{
			particles->Update(deltaTime);
		}
	}
}
void ParticleSystem::Draw(ID3D11DeviceContext* device)
{
	for (auto particle : m_ParticleStorage)
	{
		for (auto particles : particle)
		{
			particles->Draw(device);
		}
	}
}

void ParticleSystem::RemoveParticleGroup(int Position)
{
	for (int i = 0; i < m_ParticleStorage[Position].size(); i++)
	{
		delete m_ParticleStorage[Position][i];
	}
	m_ParticleStorage[Position].erase(m_ParticleStorage[Position].begin(), m_ParticleStorage[Position].end());
	m_ParticleStorage.erase(m_ParticleStorage.begin() + Position);
}

void ParticleSystem::RemoveParticleGroup(Particle* Position)
{
	for (int i = 0; i < m_ParticleStorage.size(); i++)
	{
		if (m_ParticleStorage[i][0]->ReturnType() == Position->ReturnType())
		{
			for (int j = 0; j < m_ParticleStorage[i].size(); j++)
			{
				delete m_ParticleStorage[i][j];
			}
			m_ParticleStorage[i].erase(m_ParticleStorage[i].begin(), m_ParticleStorage[i].end());
			m_ParticleStorage.erase(m_ParticleStorage.begin() + i);
			break;
		}
	}
	
}

void ParticleSystem::AddforceToParticle(Particle* Position)
{

}