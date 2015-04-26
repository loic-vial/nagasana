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
    is_fired = false;
    black=false;
    debut_rotate = false;

}

void DragonBody::display_mouth()
{
    head.display_mouth();
}

void DragonBody::draw()
{
    head.black = black;
    leftbottom.black = black;
    lefttop.black = black;
    rightbottom.black = black;
    righttop.black = black;
    neck.black = black;
    leftlegback.black = black;
    leftlegfor.black = black;
    rightlegback.black = black;
    rightlegfor.black = black;

    if(black)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
    else  glColor3ub(255,255,255);

    glPushMatrix();
    glRotated(rotate/2,1,0,0);
    glTranslatef(0,rotate/8,-rotate/12);

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

    glPopMatrix();

    if(is_fired) glEnable(GL_LIGHT2);
    else glDisable(GL_LIGHT2);
    body.setId(scale_id);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0, 20.9, 26);
    glRotatef(120, 1, 0, 0);
    body.draw();
    glRotatef(240, -1, 0, 0);
    glBindTexture(GL_TEXTURE_2D, scale_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D,scale_id);
    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL);
    if(!black) { gluQuadricTexture(params,GL_TRUE); }
    else gluQuadricTexture(params,GL_FALSE);
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
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D,scale_id);
    GLUquadric* params2 = gluNewQuadric();
    gluQuadricDrawStyle(params2,GLU_FILL);
    if(!black) { gluQuadricTexture(params2,GL_TRUE); }
    else gluQuadricTexture(params2,GL_FALSE);
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

    GLfloat ambient[] = {0.4f,0.4f,0.4f,1.0f};
    GLfloat specular[] = {1.0f,1.0f,1.0f};
    glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);

    glTranslatef(0, -2, 22);
    glRotatef(32, 1, 0, 0);
    if(black)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
    else    glColor3f(1,0,0);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, cone_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D,cone_id);
    GLUquadric* crete = gluNewQuadric();
    gluQuadricDrawStyle(crete,GLU_FILL);
    if(!black) { gluQuadricTexture(crete,GL_TRUE); }
    else gluQuadricTexture(crete,GL_FALSE);

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

    if(black)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
    else  glColor3ub(255,255,255);

    if(is_fired) glEnable(GL_LIGHT2);
    else glDisable(GL_LIGHT2);

    glPushMatrix();
    glRotated(rotate,1,0,0);
    glTranslatef(0,rotate/4,-rotate/2);

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
    glTranslatef(-rotate/14,rotate/8,rotate/14);
    righttop.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-16, 19, -13);
    glRotatef(18,1,0,0);
    glTranslatef(rotate/14,rotate/8,rotate/14);
    lefttop.draw();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 45, 49);
    glRotatef(40,1,0,0);
    head.draw();
    glPopMatrix();
}


void DragonBody::animate()
{
    leftlegfor.animate();
    rightlegfor.animate();
    // if(debut_rotate && rotate <=50)
    if(rotate <=50)
    {
        rotate +=1;
        leftlegback.debut_rotate = true;
        rightlegback.debut_rotate = true;
        leftlegfor.debut_rotate =true;
        rightlegfor.debut_rotate =true;
    }

}
