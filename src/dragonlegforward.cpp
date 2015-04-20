#include <dragonlegforward.h>

using qglviewer::Vec;
using namespace std;

DragonLegForward::DragonLegForward():
    first_part(15,0,1.5,2.5),
    second_part(13,0,1,1.5),
    joint_body(2.5, Vec(0, 0, 0)),
    joint(1.5, Vec(0, 0, 15)),
    foot(1, Vec(0, 11, 12.4))


{
}

void DragonLegForward::init(Viewer&)
{

}

void DragonLegForward::draw()
{
    glPushMatrix();

    joint_body.draw();
    first_part.draw();
    joint.draw();

    glPushMatrix();
    glTranslatef(0,0,15);
    glRotatef(120,-1,0,0);
    second_part.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,11,-6.3);
    foot.draw();
    glPopMatrix();

    glTranslatef(0,11.5,9);
    glRotatef(150,-1,0,0);
    glRotatef(90,0,0,1);
    glEnable(GL_NORMALIZE);

    //face du bas
    glBegin(GL_POLYGON);
    glNormal3f(-1, 0,0.0);
    glVertex3f(0,-1,0);
    glVertex3f(0,1,0);
    glVertex3f(0,3,5);
    glVertex3f(0,0,8);
    glVertex3f(0,-3,5);
    glVertex3f(0,-1,0);
    glEnd();
//face du haut
    glBegin(GL_POLYGON);
    glNormal3f(1, 0,0.0);
    glVertex3f(1,-1,0);
    glVertex3f(1,1,0);
    glVertex3f(1,3,5);
    glVertex3f(1,0,8);
    glVertex3f(1,-3,5);
    glVertex3f(1,-1,0);
    glEnd();
//face de la jointure
    glBegin(GL_POLYGON);
    glNormal3f(0, -1,0.0);
    glVertex3f(1,-1,0);
    glVertex3f(1,1,0);
    glVertex3f(0,1,0);
    glVertex3f(0,-1,0);
    glEnd();
//1ere face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1,-1);
    glVertex3f(1,1,0);
    glVertex3f(1,3,5);
    glVertex3f(0,3,5);
    glVertex3f(0,1,0);
    glEnd();
//2eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1,1);
    glVertex3f(1,3,5);
    glVertex3f(1,0,8);
    glVertex3f(0,0,8);
    glVertex3f(0,3,5);
    glEnd();

//3eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, -1,1.0);
    glVertex3f(1,0,8);
    glVertex3f(1,-3,5);
    glVertex3f(0,-3,5);
    glVertex3f(0,0,8);
    glEnd();

    //4eme face
        glBegin(GL_POLYGON);
        glNormal3f(0, -1,-1.0);
        glVertex3f(1,-3,5);
        glVertex3f(1,-1,0);
        glVertex3f(0,-1,0);
        glVertex3f(0,-3,5);
        glEnd();
    glPopMatrix();
}

