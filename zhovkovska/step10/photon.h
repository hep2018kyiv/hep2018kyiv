#pragma once
#include "I_ParticleDefinition.h"
#include "constants.h"
template <typename T>
class Photon : public IParticleDefinition<T>
{
protected: 
    static long N;
private:
    std::string m_name;
    T m_mass;
    T m_P;
    T m_E;
    T m_PID;
    T m_spin;
	std::string m_family;
public:
	Photon(double P) :
		 m_spin(1.0), m_family("bozon")
	{
		m_name = "photon";
		m_mass = 0.;
		m_P = P;
        m_PID = 22;
        N++;
	}
	~Photon() {}
	T getE()
	{
		return m_P * CONST::c;
	}
	std::string getName() { return m_name; }
	T getCharge() { return 0; }
	T getPID() { return m_PID; }
	static int getN() { return N;}    
	
};