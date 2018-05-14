#pragma once
#include "I_ParticleDefinition.h"
#include "constants.h"
template <typename T>
class Proton : public IParticleDefinition<T>
{
    static long N;
private:
    std::string m_name;
    T m_mass;
    T m_P;
    T m_E;
    T m_PID;
    T m_electric_charge;
    T m_spin;
    std::string m_family;
public:
    Proton(double P) :
    m_electric_charge(+1.), m_spin (0.5), m_family("barion") 
    {
        m_name = "proton";
        m_mass = 938.3;
        m_P = P;
        m_PID=2212;
        N++;
    }
    ~Proton() {}
    T getE()
    {
        return sqrt(m_P*m_P * CONST::c2 + m_mass * m_mass * CONST::c2);
    }
    std::string getName() { return m_name; }
    T getCharge() { return m_electric_charge; }
    T getPID() { return m_PID; }
    static int getN() { return N;}    
    
};