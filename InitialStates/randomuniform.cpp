#include "randomuniform.h"
#include <iostream>
#include <cassert>
#include "Math/random.h"
#include "../particle.h"
#include "../system.h"

using std::cout;
using std::endl;

RandomUniform::RandomUniform(System* system, int numberOfDimensions, int numberOfParticles) :
    InitialState(system){
        assert(numberOfDimensions > 0 && numberOfParticles > 0);
        m_numberOfDimensions = numberOfDimensions;
        m_numberOfParticles  = numberOfParticles;
        m_system->setNumberOfDimensions(numberOfDimensions);
        m_system->setNumberOfParticles(numberOfParticles);
        setupInitialState();
}

void RandomUniform::setupInitialState(){
    for (int i=0; i < m_numberOfParticles; i++){
        std::vector<double> position = std::vector<double>();
        for (int j=0; j < m_numberOfDimensions; j++){
            /* This is where you should actually place the particles in
             * some positions, according to some rule. Since this class is
             * called random uniform, they should be placed randomly according
             * to a uniform distribution here. However, later you will write
             * more sub-classes of the InitialState class in which the
             * particles are placed in other configurations.
            */
            double number = 2 * m_system->getRandomEngine()->nextDouble() - 1;
            position.push_back(number);
        }
        m_particles.push_back(new Particle());
        m_particles.at(i)->setNumberOfDimensions(m_numberOfDimensions);
        m_particles.at(i)->setPosition(position);
    }
}
