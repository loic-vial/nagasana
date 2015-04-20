#include <dragonlegbackward.h>

using qglviewer::Vec;
using namespace std;

DragonLegBackward::DragonLegBackward():
    first_part(12,0,1.5,2.5),
    second_part(9,0,1,1.5),
    joint_body(2.5, Vec(0, 0, 0)),
    joint(1.5, Vec(0, 0, 12)),
    footjoint(1, Vec(0, 5, 12.4)),
    foot()

{
}

void DragonLegBackward::init(Viewer&)
{

}

void DragonLegBackward::draw()
{
    glPushMatrix();
    joint_body.draw();
    first_part.draw();
    joint.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,12);
    glRotatef(120,-1,0,0);
    second_part.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,3,-5);
    footjoint.draw();
    glPopMatrix();

    glPushMatrix();
   glTranslatef(0,-5,0);
    glRotatef(-60,1,0,0);
    foot.draw();
    glPopMatrix();
}

