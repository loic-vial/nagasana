#include <glew.h>
#include <utils.h>
#include <cylinder.h>
#include <glut.h>
#include <glcheck.h>

#define PI 3.1416

Cylinder::Cylinder(GLfloat length , GLfloat radiusR, GLfloat radiusL)
{
    this->length = length;
    this->radiusL = radiusL;
    this->radiusR = radiusR;
}

void Cylinder::init(Viewer&)
{

}

void Cylinder::setId(GLuint id)
{
    this->id = id;
}

void Cylinder::draw()
{
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, id);
    // GLCHECK(glBindTexture(GL_TEXTURE_2D, id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    GLUquadric* cylinder = gluNewQuadric();
    glBindTexture(GL_TEXTURE_2D,id);
    gluQuadricDrawStyle(cylinder,GLU_FILL);
    gluQuadricTexture(cylinder,GL_TRUE);
    gluCylinder(cylinder,radiusL,radiusR,length,10,10);

    glPopMatrix();
}

