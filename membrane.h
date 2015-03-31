#ifndef MEMBRANE_H
#define MEMBRANE_H
#include "renderable.h"

#include <QGLViewer/vec.h>
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class Membrane
{
public:
    Membrane(qglviewer::Vec pbegin,qglviewer::Vec pmid, qglviewer::Vec pend);
    void init(Viewer&);
    void draw();

private :
    qglviewer::Vec begin;
    qglviewer::Vec mid;
    qglviewer::Vec end;
};

#endif // MEMBRANE_H
