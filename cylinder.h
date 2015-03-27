#ifndef _CYLINDER_
#define _CYLINDER_

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class Cylinder : public Renderable
{
public:

    void init(Viewer&);

    void draw();
     Cylinder(GLfloat plength,GLfloat pstarting_point,GLfloat pradiusR, GLfloat pradiusL);

private:
    GLfloat plength;
    GLfloat pstarting_point;
    GLfloat pradiusR;
    GLfloat pradiusL;
    void drawImmediate();
    void drawElements();
    void drawArrays();
};



#endif
