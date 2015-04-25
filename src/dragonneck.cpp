#include <dragonneck.h>
using qglviewer::Vec;
using namespace std;
DragonNeck::DragonNeck():
    first_part(10,0,4,9),
    second_part(8,0,3,4),
    third_part(8,0,1.5,3),
    first_joint(4, Vec(0, 0, 0)),
    second_joint(3, Vec(0, 0, 15))
{}

void DragonNeck::init(Viewer&)
{
}

void DragonNeck::draw()
{

    glColor3ub(255,255,255);

    glPushMatrix();
    first_part.draw();
    glTranslatef(0,0,10);
    first_joint.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,11);
    glRotatef(20,1,0,0);
    second_part.draw();
    glTranslatef(0,0,-7);
    second_joint.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-2.5,20);
    glRotatef(-12,1,0,0);
    third_part.draw();
    glPopMatrix();

}


