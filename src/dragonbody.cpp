#include <dragonbody.h>

void DragonBody::init(Viewer&)
{

}

void DragonBody::draw()
{
    glPushMatrix();

    glTranslatef(15, 15, 10);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glutSolidTeapot(10);

    glPopMatrix();
}

