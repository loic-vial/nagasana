#include <cylinder.h>
#include <math.h>

#define PI 3.1416

Cylinder::Cylinder(GLfloat length, GLfloat starting_point, GLfloat radiusR, GLfloat radiusL)
{
    this->length = length;
    this->radiusL = radiusL;
    this->radiusR = radiusR;
    this->starting_point = starting_point;

}

void Cylinder::init(Viewer&)
{

}

void Cylinder::draw()
{
    glPushMatrix();

    glEnable(GL_NORMALIZE);

    GLfloat angle = (2*PI)/360;
    GLfloat length = this->length+starting_point;
    GLfloat starting_point = this->starting_point;
    GLfloat radiusL = this->radiusL;
    GLfloat radiusR = this->radiusR;
    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    for (GLfloat f = 0.0 ; f<=2*PI;f+=angle)
    {
        glVertex3f(radiusL*cos(f),radiusL*sin(f), starting_point);
    }
    glEnd();


    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0);
    for (GLfloat f = 0.0 ; f<=2*PI;f+=angle)
    {
        glVertex3f(radiusR*cos(f),radiusR*sin(f), length);
    }
    glEnd();


    glBegin(GL_QUAD_STRIP);
    for (GLfloat f = 0.0 ; f<=2*PI;f+=angle)
    {
        GLfloat u1 = radiusR*cos(f+angle)-radiusL*cos(f+angle);
        GLfloat u2 =radiusR*sin(f+angle)-radiusL*sin(f+angle);
        GLfloat u3 = length-starting_point;
        GLfloat v1 = radiusL*cos(f)-radiusL*cos(f+angle);
        GLfloat v2 = radiusL*sin(f)-radiusL*sin(f+angle);
        GLfloat v3 = 0.0;
        glNormal3f(u2*v3-u3*v2, u3*v1-u1*v3, u1*v2-u2*v1);
        glVertex3f(radiusL*cos(f),radiusL*sin(f), starting_point);
        glVertex3f(radiusR*cos(f),radiusR*sin(f), length);
        glVertex3f( radiusL*cos(f+angle),radiusL*sin(f+angle), starting_point);
        glVertex3f( radiusR*cos(f+angle),radiusR*sin(f+angle), length);
    }
    glEnd();

    glPopMatrix();
}

