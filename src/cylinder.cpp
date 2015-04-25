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

    GLfloat    surf_diffuse[]={0.8,0.8,0.0,1.0};
    GLfloat surf_speculaire[]={1.0,1.0,0.0,1.0};
    GLfloat   surf_shininess[]={5.0};
    glMaterialfv(GL_FRONT,GL_DIFFUSE,surf_diffuse);
    glMaterialfv(GL_FRONT ,GL_SPECULAR,surf_speculaire);
    glMaterialfv(GL_FRONT,GL_SHININESS,surf_shininess);

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

