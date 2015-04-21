#include <membrane.h>

#include <QGLViewer/qglviewer.h>

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
    glPushMatrix();
    glEnable(GL_NORMALIZE);

    glEnable(GL_BLEND) ;
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ;

    glBegin(GL_POLYGON);
    glNormal3f(1, 0,0.0);
    glColor4ub(176,7,7,100);
    glVertex3fv(mid);

    glVertex3fv(begin);
    GLfloat angle = (2*PI)/360;
    for (GLfloat f = 0; f<=PI/2;f+=angle)
    {
        glVertex3f(0,-(end[2]-begin[2])*cos(f)+end[2], end[1]*sin(f)+begin[1]);
    }
    glVertex3fv(end);
    glVertex3fv(mid);
    glEnd();
            glDisable(GL_BLEND);
           glColor3ub(176,7,7);
    glPopMatrix();
}


