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
    scale_id = loadTexture("res/scale.jpg");
    first_membrane.init(viewer);
    second_membrane.init(viewer);
}

void DragonWing::draw()
{

    first_part.setId(scale_id);
    second_part.setId(scale_id);
    member.setId(scale_id);

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, scale_id);
    //  GLCHECK(glBindTexture(GL_TEXTURE_2D, eye_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glPushMatrix();
    GLUquadric* body = gluNewQuadric();
    gluQuadricDrawStyle(body,GLU_FILL);
    gluQuadricTexture(body,GL_TRUE);
    gluSphere(body,1.5,10,20);

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
    gluQuadricTexture(joint,GL_TRUE);
    gluSphere(joint,1,10,20);

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
    cout << "hey " << endl;
    //rotation += 10;
}
