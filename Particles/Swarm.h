#pragma once
#ifndef SWARM_H_
#define SWARM_H_
#include"Particles.h"

namespace vaibhav {
	class Swarm
	{
	public:
		const static int NPARTICLES = 10000;
	private:
		Particles *m_pParticles;
		int lastTime;
	public:
		Swarm();
		virtual ~Swarm();
		void update(int elapsed);
		const Particles *const getParticles() { return m_pParticles; };
	};
}
#endif