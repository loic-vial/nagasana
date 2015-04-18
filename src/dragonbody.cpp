#include <dragonbody.h>

void DragonBody::init(Viewer&)
{

}

void DragonBody::draw()
{
    glPushMatrix();

    glTranslatef(0, 0, 10);
    glRotatef(90, 1, 0, 0);
    glutSolidTeapot(10);

    glPopMatrix();
}

