#include "sphere.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

Sphere::Sphere(GLfloat radius_sphere)
{
    radius = radius_sphere;
}
void Sphere::init(Viewer&)
{

}

void Sphere::draw()
{
    glutSolidSphere(radius, 12, 12);
}


