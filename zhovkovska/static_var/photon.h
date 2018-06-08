#pragma once
#include "I_ParticleDefinition.h"
#include "Particle.h"
#include "constants.h"
// long Particle::N = 0;
template <typename T>
class Photon : public Particle, public IParticleDefinition<T>
{
private:
    std::string m_name;
    T m_mass;
    T m_P;
    T m_E;
    T m_PID;
    T m_spin;
	std::string m_family;
    const long current_id;
public:
	Photon(double P) :
		 m_spin(1.0), m_family("bozon"), current_id(Particle::id++)
	{
		m_name = "photon";
		m_mass = 0.;
		m_P = P;
        m_PID = 22;
    }
	~Photon() {}
	T getE()
	{
		return m_P * CONST::c;
	}
	std::string getName() { return m_name; }
	T getCharge() { return 0; }
	T getPID() { return m_PID; }
	int getId() { return current_id;}    
	
};