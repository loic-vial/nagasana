#include <dragonlegforward.h>

using qglviewer::Vec;
using namespace std;

DragonLegForward::DragonLegForward():
    first_part(15,0,1.5,2.5),
    second_part(13,0,1,1.5),
    joint_body(2.5, Vec(0, 0, 0)),
    joint(1.5, Vec(0, 0, 15)),
    footjoint(1, Vec(0, 8.3, 13.5)),
    foot()

{
}

void DragonLegForward::init(Viewer&)
{

}

void DragonLegForward::draw()
{
    glPushMatrix();

    joint_body.draw();
    first_part.draw();
    joint.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,15);
    glRotatef(80,-1,0,0);
    second_part.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,4.5,3.8);
    footjoint.draw();
    foot.draw();
    glPopMatrix();


}

