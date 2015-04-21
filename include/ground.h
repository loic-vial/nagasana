#pragma once

#include <renderable.h>
#include <glut.h>

class Ground : public Renderable
{
    public :

        Ground();

        virtual ~Ground() {}

        void init(Viewer&);

        void draw();

    private :

        GLuint texture_id;

};
