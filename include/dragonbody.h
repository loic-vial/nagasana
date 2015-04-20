#pragma once

#include <renderable.h>
#include <sphere.h>
#include <cylinder.h>
#include <glut.h>
#include <dragonlegforward.h>
#include <dragonlegbackward.h>
#include <foot.h>

class DragonBody : public Renderable
{
public :
    DragonBody();
    void init(Viewer&);

    void draw();
private :
    Cylinder body;
    DragonLegForward leftlegfor;
    DragonLegForward rightlegfor;
    DragonLegBackward leftlegback;
    DragonLegBackward rightlegback;


};
