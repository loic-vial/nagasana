#include "membrane.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#define PI 3.1416
Membrane::Membrane(qglviewer::Vec pbegin,qglviewer::Vec pmid, qglviewer::Vec pend)
{
    begin = pbegin;
    mid = pmid;
    end= pend;
}
void Membrane::init(Viewer&)
{

}

void Membrane::draw()
{

    glEnable(GL_NORMALIZE);

    glBegin(GL_POLYGON);
    glNormal3f(1, 0,0.0);


    glBegin(GL_POLYGON);
    glPolygonMode(GL_FRONT,GL_FILL);

    glPolygonMode(GL_BACK,GL_FILL);

    glVertex3fv(begin);
    glVertex3fv(mid);
    glVertex3fv(end);
    GLfloat angle = (2*PI)/360;
    GLfloat starting_point = 5;
    GLfloat radiusL = 5;
    for (GLfloat f = 0.0 ; f<=-2*PI;f-=angle)
    {
        glVertex3f(radiusL*cos(f),radiusL*sin(f), starting_point);
    }



    glEnd();

}


