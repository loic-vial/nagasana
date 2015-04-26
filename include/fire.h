#pragma once

#include <glut.h>
#include <vector>
#include <fireParticle.h>
#include <renderable.h>

class Fire : public Renderable
{
    public:

        virtual ~Fire();

        void init(Viewer &);

        void draw();

        void animate();

        void start();

        void stop();

    private:

        bool started;

        std::vector<FireParticle*> particles;

        int nbParticules;

        qglviewer::Vec initPos;

        float r;

        qglviewer::Vec defaultGravity;

        qglviewer::Vec gravity;

        double defaultMediumViscosity;

        double mediumViscosity;

        double dt;

        bool handleCollisions;

        double particleMass;

        double particleRadius;

        bool toggleGravity;

        bool toggleViscosity;

    private:

        void clear();

        void createSystemScene();

        double myRand(double min, double max);

};
