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
    if(black)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
    else  glColor3ub(255,255,255);
    GLUquadric* sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere,GLU_FILL);
    if(!black) { gluQuadricTexture(sphere,GL_TRUE); }
    else gluQuadricTexture(sphere,GL_FALSE);
     glTranslatef(getPosition().x, getPosition().y, getPosition().z);
    gluSphere(sphere,radius,10,10);
    glPopMatrix();

}


