#ifndef SPHERE_H
#define SPHERE_H
#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class Sphere
{
public:
    Sphere(GLfloat radius);
    void init(Viewer&);
    void draw();

private :
    GLfloat radius;
};

#endif // SPHERE_H
