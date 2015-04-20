#pragma once

#include <glut.h>
#include <qglviewer.h>
#include <iostream>

class Particle
{
    public:

        Particle(qglviewer::Vec pos, qglviewer::Vec vel = qglviewer::Vec(0, 0, 0), double mass = 1);

        virtual ~Particle();

        const qglviewer::Vec& getPosition() const;

        const qglviewer::Vec& getVelocity() const;

        double getMass() const;

        double getInvMass() const;

        void setPosition(const qglviewer::Vec& pos);

        void setVelocity(const qglviewer::Vec& vel);

        void incrPosition(const qglviewer::Vec& pos);

        void incrVelocity(const qglviewer::Vec& vel);

    private:

        qglviewer::Vec position;

        qglviewer::Vec velocity;

        double mass;

        double invMass;
};

std::ostream& operator<<(std::ostream& os, const Particle& p);
