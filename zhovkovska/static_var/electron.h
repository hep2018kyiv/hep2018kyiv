#pragma once
#include "I_ParticleDefinition.h"
#include "Particle.h"
#include "constants.h"
// long Particle::N = 0;
template <typename T>
class Electron : public Particle, public IParticleDefinition<T>
{
private:
    std::string m_name;
    T m_mass;
    T m_P;
    T m_electric_charge;
	T m_spin;
    T m_E;
    T m_PID;
    std::string m_family;
    const long current_id;
public:
	Electron(double P) :
		m_electric_charge(-1.), m_spin (0.5), m_family("lepton"), current_id(Particle::id++)
	    {
       	 m_name = "electron";
		 m_mass = 0.511;
		 m_P = P;
         m_PID = 11;
        }
	~Electron() {}
	T getE()
	{
		return sqrt(m_P*m_P * CONST::c2 + m_mass * m_mass * CONST::c2);
	}
	std::string getName() { return m_name; }
	T getCharge() { return m_electric_charge; }
	T getPID() { return m_PID; }
	int getId() { return current_id;}    
};