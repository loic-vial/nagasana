#include <dragonbody.h>
using qglviewer::Vec;

DragonBody::DragonBody():
    body(20,0,9,10),
    leftlegfor(),
    rightlegfor(),
    leftlegback(),
    rightlegback()
{}

  void DragonBody::init(Viewer&)
{

}

void DragonBody::draw()
{

    glPushMatrix();
    glTranslatef(-8, 0, 16);
    glRotatef(120,1,0,0);
    glRotatef(-18,0,1,0);
    glRotatef(180,0,0,1);
    leftlegback.draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(8, 0, 16);
    glRotatef(120,1,0,0);
    glRotatef(18,0,1,0);
    glRotatef(180,0,0,1);
    rightlegback.draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 20.9, 26);
    glRotatef(120, 1, 0, 0);
    body.draw();
    glutSolidSphere(10, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4, 16.4);
    glRotatef(100, 1, 0, 0);
    glutSolidSphere(9, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8, 20, 26);
    glRotatef(160,1,0,0);
    glRotatef(-28,0,1,0);
    glRotatef(180,0,0,1);
    leftlegfor.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8, 20, 26);
    glRotatef(160,1,0,0);
    glRotatef(28,0,1,0);
    glRotatef(180,0,0,1);
    rightlegfor.draw();
    glPopMatrix();










}

