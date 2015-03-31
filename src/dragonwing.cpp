#include "dragonwing.h"

using qglviewer::Vec;
using namespace std;

DragonWing::DragonWing():
    first_part(25,0,1,1.5),
    second_part(20,0,0.5,1),
    joint_body(1.5, Vec(0, 0, 0)),
    joint(2, Vec(0, 0, 25))
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
    joint.draw();

    glPushMatrix();
    glTranslatef(0,0,25);
    glRotatef(70,-50,0,0);
    second_part.draw();
    glPopMatrix();

    glPopMatrix();
}

