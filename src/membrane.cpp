#include <membrane.h>

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


    glVertex3fv(mid);

    glVertex3fv(begin);
    GLfloat angle = (2*PI)/360;
    for (GLfloat f = 0; f<=PI/2;f+=angle)
    {
        glVertex3f(0,-16*cos(f)+17, 10*sin(f)+5);
    }
    glVertex3fv(end);
    glVertex3fv(mid);
    glEnd();

}


