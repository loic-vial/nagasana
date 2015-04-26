#include <tree.h>
#include <utils.h>

void Tree::init(Viewer&)
{
    texture = loadTexture("res/tree.jpg");
}

void Tree::draw()
{
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricNormals(params, GLU_SMOOTH);
    gluQuadricTexture(params, GL_TRUE);
    gluCylinder(params, 50, 50, 500, 10, 10);
    gluDeleteQuadric(params);

    glPopMatrix();
}
