﻿#pragma once
#include <string>
#include <vector>

template <typename T>
class IParticleDefinition
{
protected:
//     T m_Phi;
//     T m_Theta;
public:
    static long N;
	virtual std::string getName(){};
	virtual ~IParticleDefinition(){};
    
	virtual T getE()=0;
    virtual T getCharge()=0;
    virtual T getPID()=0;
//     virtual static int getN()=0;
};