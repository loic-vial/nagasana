#include <dragonwing.h>
#include <utils.h>
#include <iostream>

using qglviewer::Vec;
using namespace std;

DragonWing::DragonWing():
    first_part(25,1,1.5),
    second_part(22,0.5,1),
    member(20,0.3,1),
    first_membrane(qglviewer::Vec(0,0,0), qglviewer::Vec(0,0,25),qglviewer::Vec(0,17,15)),
    second_membrane(qglviewer::Vec(0,17,15),qglviewer::Vec(0,0,25),qglviewer::Vec(0,17,39))
{

}

void DragonWing::init(Viewer& viewer)
{
    scale_id = loadTexture("res/corne.jpg");
    first_membrane.init(viewer);
    second_membrane.init(viewer);
    black=false;
}

void DragonWing::draw()
{
    first_part.setId(scale_id);
    second_part.setId(scale_id);
    member.setId(scale_id);
    first_membrane.black= black;
    second_membrane.black = black;

    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
    else  glColor3ub(255,255,255);

    if(black) glDisable(GL_TEXTURE_2D);
    else glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, scale_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glPushMatrix();
    GLUquadric* body = gluNewQuadric();
    gluQuadricDrawStyle(body,GLU_FILL);
    if(!black) { gluQuadricTexture(body,GL_TRUE); }
    else gluQuadricTexture(body,GL_FALSE);
    gluSphere(body,1.5,10,10);
    first_part.draw();
    glPopMatrix();

    glPushMatrix();
    first_membrane.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,25);
    glRotatef(50,1,0,0);
    GLUquadric* joint = gluNewQuadric();
    gluQuadricDrawStyle(joint,GLU_FILL);
    if(!black) { gluQuadricTexture(joint,GL_TRUE); }
    else gluQuadricTexture(joint,GL_FALSE);
    gluSphere(joint,1,10,10);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,25);
    glRotatef(120,-1,0,0);
    //glRotatef(rotation, 0, 0.3, 0.3);
    member.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,25);
    glRotatef(50,-50,0,0);
    //glRotatef(rotation, 0, 0.3, 0.3);
    second_part.draw();
    glPopMatrix();

    glPushMatrix();
    second_membrane.draw();
    glPopMatrix();
}

void DragonWing::animate()
{

}
