#pragma once

#include <cylinder.h>
#include <sphere.h>
#include <renderable.h>
#include <glut.h>
#include <membrane.h>
#include <foot.h>

class DragonLegBackward : public Renderable
{
public :


    DragonLegBackward();
    void init(Viewer&);

    void draw();


    void animate();
    bool black;
    bool debut_rotate;


private :
    Cylinder first_part;
    Cylinder second_part;
    GLuint scale_id;

    GLfloat rotate;
};

