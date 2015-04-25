#include <dragonwing.h>
#include <utils.h>
using qglviewer::Vec;
using namespace std;

DragonWing::DragonWing():
    first_part(25,1,1.5),
    second_part(22,0.5,1),
    member(20,0.3,1),
    joint_body(1.5, Vec(0, 0, 0)),
    joint(2, Vec(0, 0, 25)),
    first_membrane(qglviewer::Vec(0,0,0), qglviewer::Vec(0,0,25),qglviewer::Vec(0,17,15)),
    second_membrane(qglviewer::Vec(0,17,15),qglviewer::Vec(0,0,25),qglviewer::Vec(0,17,39))
{
}

void DragonWing::init(Viewer& viewer)
{
     scale_id = loadTexture("res/scale.jpg");
first_membrane.init(viewer);
second_membrane.init(viewer);
}

void DragonWing::draw()
{

    first_part.setId(scale_id);
    second_part.setId(scale_id);
    member.setId(scale_id);
    glPushMatrix();
    joint_body.draw();
    first_part.draw();
    glPopMatrix();

    glPushMatrix();
    first_membrane.draw();
    glPopMatrix();

     glPushMatrix();
    joint.draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0,25);
    glRotatef(120,-1,0,0);
    member.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,25);
    glRotatef(50,-50,0,0);
    second_part.draw();
    glPopMatrix();

    glPushMatrix();
    second_membrane.draw();
    glPopMatrix();


}

