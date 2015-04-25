#include <glew.h>
#include <utils.h>
#include <dragonlegbackward.h>
#include <glut.h>
#include <glcheck.h>
using qglviewer::Vec;
using namespace std;

DragonLegBackward::DragonLegBackward():
    first_part(12,1.5,2.5),
    second_part(9,1,1.5)
{
}

void DragonLegBackward::init(Viewer&)
{
    scale_id = loadTexture("res/scale.jpg");
}

void DragonLegBackward::draw()
{
    first_part.setId(scale_id);
    second_part.setId(scale_id);

    glPushMatrix();
    glColor3ub(255,255,255);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, scale_id);
    //   GLCHECK(glBindTexture(GL_TEXTURE_2D,scale_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    GLUquadric* joint = gluNewQuadric();
    gluQuadricDrawStyle(joint,GLU_FILL);
    gluQuadricTexture(joint,GL_TRUE);
    gluSphere(joint,2.5,10,20);

    first_part.draw();
    glTranslatef(0,0,12);
    gluSphere(joint,1.5,10,20);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,12);
    glRotatef(120,-1,0,0);
    second_part.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,7.8,7.5);
    gluSphere(joint,1,10,20);

    glPopMatrix();

    gluDeleteQuadric(joint);

}

