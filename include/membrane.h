#pragma once

#include <renderable.h>
#include <QGLViewer/vec.h>
#include <glut.h>

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
