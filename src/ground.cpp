#include <ground.h>
#include <glut.h>

using namespace std;

Ground::Ground()
{

}

void Ground::draw()
{
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(-100, -100, 0);
    glVertex3f(-100, 100,  0);
    glVertex3f( 100, 100,  0);
    glVertex3f( 100, -100, 0);
    glEnd();
}
