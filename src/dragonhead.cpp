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
    face.draw();
    glutSolidSphere(5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0,9);
    glutSolidSphere(5.5, 20, 20);
    glPopMatrix();
}

