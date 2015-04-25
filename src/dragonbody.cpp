#include <glew.h>
#include <utils.h>
#include <dragonbody.h>
#include <glut.h>
#include <glcheck.h>
using qglviewer::Vec;

DragonBody::DragonBody():
    body(20,9,10),
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
    leftlegback.init(v);
    leftlegfor.init(v);
    rightlegback.init(v);
    rightlegfor.init(v);
    cone_id = loadTexture("res/corne.jpg");
    scale_id = loadTexture("res/scale.jpg");
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
    body.setId(scale_id);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0, 20.9, 26);
    glRotatef(120, 1, 0, 0);
    body.draw();
    glColor3ub(255,255,255);
    glRotatef(240, -1, 0, 0);
    glBindTexture(GL_TEXTURE_2D, scale_id);
    //   GLCHECK(glBindTexture(GL_TEXTURE_2D, scale_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D,scale_id);
    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL);
    gluQuadricTexture(params,GL_TRUE);
    glRotatef(95, -1, 0, 0);
    gluSphere(params,10,10,10);
    gluDeleteQuadric(params);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4, 16.4);
    glRotatef(100, 1, 0, 0);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, scale_id);
    //  GLCHECK(glBindTexture(GL_TEXTURE_2D, scale_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D,scale_id);
    GLUquadric* params2 = gluNewQuadric();
    gluQuadricDrawStyle(params2,GLU_FILL);
    gluQuadricTexture(params2,GL_TRUE);
    gluSphere(params2,9,10,10);
    gluDeleteQuadric(params2);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 23,29);
    glRotatef(-30,1,0,0);
    neck.draw();
    glPopMatrix();

    glDisable(GL_LIGHT2);

    //crete
    glPushMatrix();
    glTranslatef(0, -2, 22);
    glRotatef(32, 1, 0, 0);
    glColor3f(0.5,0.5,1);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, cone_id);
    // GLCHECK(glBindTexture(GL_TEXTURE_2D, cone_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D,cone_id);
    GLUquadric* crete = gluNewQuadric();
    gluQuadricDrawStyle(crete,GLU_FILL);
    gluQuadricTexture(crete,GL_TRUE);
    gluCylinder(crete,2,0,8,10,1);
    glTranslatef(0, 5, 0);
    gluCylinder(crete,2,0,8,10,1);
    glTranslatef(0, 5, 0);
    gluCylinder(crete,2,0,8,10,1);
    glTranslatef(0, 5, 0);
    gluCylinder(crete,2,0,8,10,1);
    glTranslatef(0, 5, 0);
    gluCylinder(crete,2,0,8,10,1);
    glTranslatef(0, 5, 0);
    gluCylinder(crete,2,0,8,10,1);
    glTranslatef(0, 5, 0);
    gluCylinder(crete,2,0,8,10,1);
    gluDeleteQuadric(crete);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glEnable(GL_LIGHT2);

    glPushMatrix();
    glColor3ub(255,255,255);
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

