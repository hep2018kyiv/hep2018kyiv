#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
#include <memory>
#include "electron.h"
#include "photon.h"
#include "proton.h"
#include "I_ParticleDefinition.h"
#include "Particle.h"

long Particle::id = 0;

int main()
{
	Electron<double> e(0.01);
	std::cout.precision(std::numeric_limits< double >::max_digits10);
	std::cout << "E: " << e.getE() <<"\t N: "<<e.getId()<< std::endl;
	Photon<double> p(0.02);
    std::cout << "E: " << p.getE() <<"\t N: "<<p.getId() << std::endl;

	std::vector<std::unique_ptr<IParticleDefinition<double>>> particals;
	std::unique_ptr<IParticleDefinition<double>> pt;
	for (int num = 0; num < 100; ++num)
	{
		if (static_cast<float>(std::rand()) / RAND_MAX < 0.33)
		{
			pt = std::unique_ptr<IParticleDefinition<double>>(new Electron<double>(static_cast<float>(std::rand()) / RAND_MAX));
		}
		else if (static_cast<float>(std::rand()) / RAND_MAX < 0.66)
		{
			pt = std::unique_ptr<IParticleDefinition<double>>(new Photon<double>(static_cast<float>(std::rand()) / RAND_MAX));
		}
		else 
        {
            pt = std::unique_ptr<IParticleDefinition<double>>(new Proton<double>(static_cast<float>(std::rand()) / RAND_MAX));
        }
        particals.emplace_back(std::move(pt));
	}
	
	for (auto const& particle : particals)
	{
		double E = particle->getE();
        double c = particle->getCharge();
        std::cout << "name: " << particle->getName() << "\tE:" << E << "\tcharge:" << c <<" N:  "<< particle->getId()<<"\n";
	}
	return 0;
}