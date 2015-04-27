#pragma once

#include <particle.h>
#include <qglviewer.h>

class Spring 
{
    public:

        Spring(const Particle *p1, const Particle *p2, double s, double l0, double d);

        qglviewer::Vec getCurrentForce() const;

        const Particle* getParticle1() const;

        const Particle* getParticle2() const;

        void draw() const;

    private:

        const Particle *p1, *p2;

        double stiffness;

        double equilibriumLength;

        double damping;
};

