#pragma once
#ifndef PARTICLES_H_
#define PARTICLES_H_
namespace vaibhav {
	class Particles
	{
    public:
		double m_x;
		double m_y;
	private: 
		double m_speed;
		double m_direction;
    private:
		void init();
	public:
		Particles();
		void update(int interval);
		virtual ~Particles();
	};
}
#endif