#include <dragonhead.h>

DragonHead::DragonHead():
    face(9,0,5.5,5)
{}

void DragonHead::init(Viewer&)
{

}

void DragonHead::draw()
{
    glPushMatrix();
    glColor3ub(255,255,255);
    face.draw();
    glutSolidSphere(5, 20, 20);
    glPopMatrix();

    glPushMatrix();
      glColor3ub(255,255,255);
    glTranslatef(0, 0,9);
    glutSolidSphere(5.5, 20, 20);
    glPopMatrix();
}

