#include <tree.h>
#include <utils.h>

void Tree::init(Viewer&)
{
    texture_trunk = loadTexture("res/tree.jpg");
    texture_foliage = loadTexture("res/foliage.jpg");
}

void Tree::draw()
{
    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation, 0, 0, 1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_trunk);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricNormals(params, GLU_SMOOTH);
    gluQuadricTexture(params, GL_TRUE);
    gluCylinder(params, 50, 50, 500, 10, 10);
    gluDeleteQuadric(params);

    glTranslatef(0, 0, 400);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_foliage);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    GLUquadric* params2 = gluNewQuadric();
    gluQuadricDrawStyle(params2, GLU_FILL);
    gluQuadricNormals(params2, GLU_SMOOTH);
    gluQuadricTexture(params2, GL_TRUE);
    gluSphere(params2, 200, 10, 10);
    gluDeleteQuadric(params2);

    glPopMatrix();
}
