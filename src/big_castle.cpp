#include <glew.h>
#include <utils.h>
#include <big_castle.h>
#include <glut.h>
#include <glcheck.h>
using qglviewer::Vec;

BigCastle::BigCastle():
first(140,70,20),
second(50,50,8)
{
}

void BigCastle::init(Viewer& v)
{

   first.init(v);
   second.init(v);
}


void BigCastle::draw()
{
    glPushMatrix();
glTranslatef(600,600,0);
glRotatef(45,0,0,-1);
    first.draw();
    glTranslatef(0,0,70);
second.draw();
glPopMatrix();
}


void BigCastle::animate()
{
}


