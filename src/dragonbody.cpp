#include <dragonbody.h>
using qglviewer::Vec;

DragonBody::DragonBody():
    body(20,0,9,10),
  leftleg(),
    rightleg()
{}

void DragonBody::init(Viewer&)
{

}

void DragonBody::draw()
{
   glPushMatrix();
    glTranslatef(0, 24, 20);
    glRotatef(100, 1, 0, 0);
    body.draw();
    glutSolidSphere(10, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4, 16.4);
    glRotatef(100, 1, 0, 0);
    glutSolidSphere(9, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8, 24, 16);
    glRotatef(120,1,0,0);
    glRotatef(-25,0,1,0);

    glRotatef(180,0,0,1);
   leftleg.draw();
    glPopMatrix();

}

