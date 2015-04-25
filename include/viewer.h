#pragma once

#include <glut.h>
#include <qglviewer.h>
#include <list>

class Renderable;

class Viewer : public QGLViewer
{
    public :

        virtual ~Viewer();

        void addRenderable(Renderable* r);

    protected :

        std::list<Renderable*> renderableList;

        virtual void init();

        virtual void draw();

        virtual void animate();

    protected :

        bool toogleWireframe;

        bool toogleLight;

        virtual void keyPressEvent(QKeyEvent *e);

        virtual void mouseMoveEvent(QMouseEvent *e);

        virtual QString helpString() const;
};

