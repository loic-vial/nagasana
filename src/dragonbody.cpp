#include <glew.h>
#include <utils.h>
#include <dragonbody.h>
#include <glut.h>
#include <glcheck.h>
using qglviewer::Vec;

DragonBody::DragonBody():
    body(20,0,9,10),
    leftlegfor(),
    rightlegfor(),
    leftlegback(),
    rightlegback(),
    lefttop(),
    leftbottom(),
    righttop(),
    rightbottom(),
    head(),
    neck()
{}

void DragonBody::init(Viewer& v)
{
    leftbottom.init(v);
    lefttop.init(v);
    rightbottom.init(v);
    righttop.init(v);
    head.init(v);
    neck.init(v);
    cone_id = loadTexture("res/corne.jpg");
}


void DragonBody::draw()
{


    glDisable(GL_LIGHT2);
    glPushMatrix();
    glTranslatef(-8, 0, 16);
    glRotatef(120,1,0,0);
    glRotatef(-18,0,1,0);
    glRotatef(180,0,0,1);
    leftlegback.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, -10, -14.5);
    glRotatef(20,1,0,0);
    leftbottom.draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(8, 0, 16);
    glRotatef(120,1,0,0);
    glRotatef(18,0,1,0);
    glRotatef(180,0,0,1);
    rightlegback.draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(10, -10, -14.5);
    glRotatef(20,1,0,0);
    rightbottom.draw();
    glPopMatrix();


    glEnable(GL_LIGHT2);
    glPushMatrix();
    glTranslatef(0, 20.9, 26);
    glRotatef(120, 1, 0, 0);
    body.draw();
    glutSolidSphere(10, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 23,29);
    glRotatef(-30,1,0,0);
    neck.draw();
    glPopMatrix();

    glDisable(GL_LIGHT2);

    //crete
    glPushMatrix();
    glTranslatef(0, 8, 17);
    glRotatef(32, 1, 0, 0);
    glTranslatef(0, -1, 10);
    glEnable(GL_TEXTURE_2D);
    GLCHECK(glBindTexture(GL_TEXTURE_2D, cone_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D,cone_id);
    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL);
    gluQuadricTexture(params,GL_TRUE);
    gluCylinder(params,2,0,8,20,1);
    glTranslatef(0, 5, 0);
    gluCylinder(params,2,0,8,20,1);
    glTranslatef(0, 5, 0);
    gluCylinder(params,2,0,8,20,1);
    glTranslatef(0, 5, 0);
    gluCylinder(params,2,0,8,20,1);
    glTranslatef(0, 5, 0);
    gluCylinder(params,2,0,8,20,1);
    glTranslatef(0, 5, 0);
    gluCylinder(params,2,0,8,20,1);
    gluDeleteQuadric(params);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glEnable(GL_LIGHT2);

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

    glPushMatrix();
    glTranslatef(16, 19, -13);
    glRotatef(18,1,0,0);
    righttop.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-16, 19, -13);
    glRotatef(18,1,0,0);
    lefttop.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 45, 49);
    glRotatef(40,1,0,0);
    head.draw();
    glPopMatrix();

}

