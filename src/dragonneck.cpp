#include <dragonneck.h>
using qglviewer::Vec;
using namespace std;
DragonNeck::DragonNeck():
    first_part(10,0,6,9),
    second_part(8,0,5,6),
    third_part(8,0,4.5,5),
    first_joint(6, Vec(0, 0, 0)),
    second_joint(5, Vec(0, 0, 15))
{}

void DragonNeck::init(Viewer&)
{
}

void DragonNeck::draw()
{
    glPushMatrix();
    first_part.draw();
    glTranslatef(0,0,10);
    first_joint.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,11);
    glRotatef(20,1,0,0);
    second_part.draw();
    glTranslatef(0,0,-5);
    second_joint.draw();
    glPopMatrix();

    glPushMatrix();
  glTranslatef(0,0,20);
  glRotatef(-20,1,0,0);
    third_part.draw();
    glPopMatrix();

}


