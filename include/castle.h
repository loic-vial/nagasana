#pragma once
#include <renderable.h>
#include <glut.h>
#include <fire.h>

class Castle : public Renderable
{
public:

    Castle(GLfloat l,GLfloat h,GLfloat r);
    void init(Viewer&);

    void draw();

    void animate();
    void wall(GLuint id);
    void tower();
    bool burned;
bool black;
private:
    GLfloat lenght ;
    GLfloat hight ;
    GLfloat radius;
    GLuint wall_id;
    GLuint door_id;
    GLuint wall_burned;
    GLuint door_burned;

    Fire fire;


};
