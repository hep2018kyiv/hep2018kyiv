#pragma once
#include "I_ParticleDefinition.h"
#include "constants.h"
// long Particle::N = 0;
template <typename T>
class Proton : public Particle, public IParticleDefinition<T>
{
private:
    std::string m_name;
    T m_mass;
    T m_P;
    T m_E;
    T m_PID;
    T m_electric_charge;
    T m_spin;
    std::string m_family;
    const long current_id;
public:
    Proton(double P) :
    m_electric_charge(+1.), m_spin (0.5), m_family("barion"), current_id(Particle::id++) 
    {
        m_name = "proton";
        m_mass = 938.3;
        m_P = P;
        m_PID=2212;
    }
    ~Proton() {}
    T getE()
    {
        return sqrt(m_P*m_P * CONST::c2 + m_mass * m_mass * CONST::c2);
    }
    std::string getName() { return m_name; }
    T getCharge() { return m_electric_charge; }
    T getPID() { return m_PID; }
    int getId() { return current_id;}    
    
};