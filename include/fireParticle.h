#pragma once

#include <qglviewer.h>
#include <iostream>

class FireParticle
{
    public:

        FireParticle(qglviewer::Vec pos, qglviewer::Vec vel, double m, double r, double l, double rd, double gr, double bl);

        virtual ~FireParticle();

        const qglviewer::Vec& getPosition() const;

        const qglviewer::Vec& getVelocity() const;

        double getMass() const;

        double getInvMass() const;

        double getRadius() const;

        double life;

        double red, green, blue;

        void setPosition(const qglviewer::Vec &pos);

        void setVelocity(const qglviewer::Vec &vel);

        void incrPosition(const qglviewer::Vec &pos);

        void incrVelocity(const qglviewer::Vec &vel);

        void incrLife(int cste);

        void setLife(int cste);

        void draw() const;

    private:

        qglviewer::Vec position;

        qglviewer::Vec velocity;

        double mass;

        double invMass;

        double size;
};

// output stream operator, as non-member
std::ostream& operator<<(std::ostream& os, const FireParticle& p);

