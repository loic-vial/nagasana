#include <dragonwing.h>

using qglviewer::Vec;
using namespace std;

DragonWing::DragonWing():
    first_part(25,0,1,1.5),
    second_part(22,0,0.5,1),
    member(20,0,0.3,1),
    joint_body(1.5, Vec(0, 0, 0)),
    joint(2, Vec(0, 0, 25)),
    first_membrane(qglviewer::Vec(0,0,0), qglviewer::Vec(0,0,25),qglviewer::Vec(0,17,15)),
    second_membrane(qglviewer::Vec(0,0,0),qglviewer::Vec(0,0,0),qglviewer::Vec(0,0,0))
{
}

void DragonWing::init(Viewer&)
{

}

void DragonWing::draw()
{
    glPushMatrix();

    joint_body.draw();
    first_part.draw();

    glPushMatrix();
    first_membrane.draw();
    glPopMatrix();

    joint.draw();

    glPushMatrix();
    glTranslatef(0,0,25);
    glRotatef(120,-1,0,0);
    member.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,25);
    glRotatef(50,-50,0,0);
    second_part.draw();
    glPopMatrix();

    glPopMatrix();
}

