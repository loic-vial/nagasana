#pragma once

#include <renderable.h>
#include <glut.h>
#include <qglviewer.h>

class Tree : public Renderable
{
    public :

        void init(Viewer& v);

        void draw();

        qglviewer::Vec position;

        float rotation;

    private :

        GLuint texture_trunk;

        GLuint texture_foliage;
};
