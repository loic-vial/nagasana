#pragma once

#include <renderable.h>
#include <glut.h>
#include <fire.h>

class Castle : public Renderable
{
    public:

        Castle(GLfloat l, GLfloat h, GLfloat r);

        void init(Viewer&);

        void draw();

        void animate();

        void wall(GLuint id);

        void tower();

        void burn1();

        void burn2();

        void burn3();

        int burn_level;

        bool black;

    private:

        GLfloat lenght ;

        GLfloat hight ;

        GLfloat radius;

        GLuint texture_wall, texture_wall1, texture_wall2, texture_wall3, current_texture_wall;

        GLuint texture_door, texture_door1, texture_door2, texture_door3, current_texture_door;

        Fire fire;

};
