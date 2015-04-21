#include <ground.h>
#include <glew.h>
#include <glut.h>
#include <QKeyEvent>
#include <iostream>
#include <cstdio>
#include <QGLViewer/qglviewer.h>
#include <stdexcept>
#include <utils.h>

using namespace std;

Ground::Ground()
{

}

void Ground::init(Viewer&)
{

   /* glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    texture_id = loadTexture("res/ground_texture.png");
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        cout << "hdsdfs" << endl;
    }
    program.load("shaders/texture.vert", "shaders/texture.frag");
    GLint program_id = (GLint)program;
    GLCHECK(glUseProgram(program_id));
    GLCHECK(texture0 = glGetUniformLocation(program_id, "texture0"));
    GLCHECK(texcoord0 = glGetAttribLocation(program_id, "texcoord0"));
    GLCHECK(glUniform1i(texture0, 0 ));*/
}

void Ground::draw()
{
  /*  GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_id));
    GLCHECK(glUseProgram((GLint)program));
    GLCHECK(glActiveTexture(GL_TEXTURE0));
    GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_id));
    GLCHECK(glUniform1i(texture0, 0));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glNormal3f(0.0, 0.0, 1.0);*/

    glPushMatrix();

    glBegin(GL_QUADS);

  //  glVertexAttrib2f(texcoord0, 0, 0);
  //   glTexCoord2d(0, 0);
    glVertex3f(-100, -100, 0);

  //  glVertexAttrib2f(texcoord0, 0, 10);
   // glTexCoord2d(0, 10);
    glVertex3f(-100, 100,  0);

   // glVertexAttrib2f(texcoord0, 10, 10);
   // glTexCoord2d(10, 10);
    glVertex3f(100, 100,  0);

   // glVertexAttrib2f(texcoord0, 10, 0);
   // glTexCoord2d(10, 0);
    glVertex3f(100, -100, 0);

    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
