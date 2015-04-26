#include <sphere.h>
#include <glut.h>
#include <utils.h>
using qglviewer::Vec;

Sphere::Sphere(GLfloat r, Vec position, Vec vel, GLfloat mass) :
    Particle(position, vel, mass),
    radius(r)
{
    id = loadTexture("res/scale.jpg");
    black = false;
}

void Sphere::draw()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    if(black)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
    else  glColor3ub(0,0,0);
    GLUquadric* sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere,GLU_FILL);
    if(!black) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,id);
        gluQuadricTexture(sphere,GL_TRUE);
    }
    else gluQuadricTexture(sphere,GL_FALSE);
    glTranslatef(getPosition().x, getPosition().y, getPosition().z);
    gluSphere(sphere,radius,10,10);
    glPopMatrix();


}
