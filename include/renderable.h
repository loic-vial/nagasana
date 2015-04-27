#pragma once

#include <QKeyEvent>

class Viewer;

class Renderable
{
    public:

        virtual ~Renderable() {}

        virtual void init(Viewer&) {}

        virtual void draw() = 0;

        virtual void animate() {}

        virtual void keyPressEvent(QKeyEvent*, Viewer&) {}

        virtual void mouseMoveEvent(QMouseEvent*, Viewer&) {}
};
