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
    //load texture
    //membrane_texture = loadTexture("");
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
        glVertex3f(0,-(end[2]-begin[2])*cos(f)+end[2], end[1]*sin(f)+begin[1]);
    }
    glVertex3fv(end);
    glVertex3fv(mid);
    glEnd();

}


