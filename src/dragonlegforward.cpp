#include<glew.h>
#include <dragonlegforward.h>

using qglviewer::Vec;
using namespace std;

DragonLegForward::DragonLegForward():
    first_part(15,0,2,3.5),
    second_part(13,0,1,2),
    joint_body(3.5, Vec(0, 0, 0)),
    joint(2, Vec(0, 0, 15)),
    footjoint(1, Vec(0, 8.3, 13.5))
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
    glPopMatrix();


}
