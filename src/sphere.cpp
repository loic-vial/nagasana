#include <sphere.h>
#include <glut.h>

using qglviewer::Vec;

Sphere::Sphere(GLfloat r, Vec position, Vec vel, GLfloat mass) :
    Particle(position, vel, mass),
    radius(r)
{

}

void Sphere::draw()
{
    glPushMatrix();
      glColor3ub(176,7,7);
    glTranslatef(getPosition().x, getPosition().y, getPosition().z);
    glutSolidSphere(radius, 12, 12);
    glPopMatrix();
}


