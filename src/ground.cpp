#include <glew.h>
#include <ground.h>
#include <glut.h>
#include <QKeyEvent>
#include <iostream>
#include <cstdio>
#include <QGLViewer/qglviewer.h>
#include <stdexcept>
#include <utils.h>
#include <glcheck.h>

using namespace std;

Ground::Ground()
{

}

void Ground::init(Viewer&)
{

    texture_id = loadTexture("res/ground_texture.png");
}

void Ground::draw()
{

    glEnable(GL_TEXTURE_2D);
    GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glPushMatrix();

    glNormal3f(0, 0, 1);

    glBegin(GL_QUADS);

    glTexCoord2d(0, 0); glVertex3f(-1000, -1000, 0);
    glTexCoord2d(0, 10); glVertex3f(-1000, 1000, 0);
    glTexCoord2d(10, 10); glVertex3f(1000, 1000, 0);
    glTexCoord2d(10, 0); glVertex3f(1000, -1000, 0);

    glEnd();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
