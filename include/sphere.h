#pragma once

#include <glut.h>
#include <particle.h>

class Sphere : public Particle
{
    public:

        Sphere(GLfloat radius = 1, qglviewer::Vec pos = qglviewer::Vec(0, 0, 0), qglviewer::Vec vel = qglviewer::Vec(0, 0, 0), GLfloat mass = 1);

        void draw();

    private :

        GLfloat radius;
};

