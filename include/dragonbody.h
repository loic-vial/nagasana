#pragma once
#include<glew.h>
#include <renderable.h>
#include <sphere.h>
#include <cylinder.h>
#include <glut.h>
#include <dragonlegforward.h>
#include <dragonlegbackward.h>
#include <foot.h>
#include <dragonhead.h>
#include <dragonneck.h>

class DragonBody : public Renderable
{
public :

    DragonBody();

    void init(Viewer&);

    void draw();

    void display_mouth();


    void animate();

    bool black;
    bool is_fired;

    bool debut_rotate;
private :
    Cylinder body;
    DragonLegForward leftlegfor;
    DragonLegForward rightlegfor;
    DragonLegBackward leftlegback;
    DragonLegBackward rightlegback;
    Foot lefttop;
    Foot leftbottom;
    Foot righttop;
    Foot rightbottom;
    DragonHead head;
    DragonNeck neck;
    GLfloat rotate;
    GLuint cone_id;

    GLuint scale_id;

};
