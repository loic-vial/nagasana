#include <glew.h>
#include <utils.h>
#include <membrane.h>
#include <glut.h>
#include <glcheck.h>
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
    membrane_id=loadTexture("res/metal.jpg");
}

void Membrane::draw()
{
    glPushMatrix();
    glEnable(GL_NORMALIZE);

    glEnable(GL_BLEND) ;
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ;

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glBegin(GL_POLYGON);
    glNormal3f(1, 0,0);
    glColor4ub(255,255,255,150);
    glVertex3fv(mid);

    glVertex3fv(begin);
    GLfloat angle = (2*PI)/360;
    for (GLfloat f = 0; f<=PI/2;f+=angle)
    {
        glVertex3f(0,-(end[2]-begin[2])*cos(f)+end[2], end[1]*sin(f)+begin[1]);
    }
    glVertex3f(0,end[1],end[2]+begin[0]);
    glVertex3fv(mid);
    glEnd();
    glDisable(GL_BLEND);
    glColor3ub(255,255,255);
    glPopMatrix();
}


