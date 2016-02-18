#include "harmonicoscillatorinteracting.h"
#include "system.h"
#include "particle.h"

HarmonicOscillatorInteracting::HarmonicOscillatorInteracting(System* system,
                                                             double gamma) :
        HarmonicOscillator(system, 1.0) {
    m_gamma = 1.0;
    m_a = 0.0043;
    m_a2 = m_a*m_a;
    m_exactGroundStateEnergyKnown = false;
}

double HarmonicOscillatorInteracting::computeLocalEnergy(Particle* particles) {
    double nonInteractionEnergy = HarmonicOscillator::computeLocalEnergy(particles);
    double interactionEnergy = 0;

    for (int i=0; i<m_system->getNumberOfParticles(); i++) {
        for (int j=i+1; j<m_system->getNumberOfParticles(); j++) {
            double r2 = 0;
            for (int k=0; k<m_system->getNumberOfDimensions(); k++) {
                const double x = particles[i].getPosition()[k] - particles[j].getPosition()[j];
                r2 += x*x;
            }
            interactionEnergy += (r2 < m_a2) * 1e10;
        }
    }
    return nonInteractionEnergy + interactionEnergy;
}