#include <glew.h>
#include <utils.h>
#include <foot.h>
#include <glut.h>

void Foot::init(Viewer &)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    foot_id = loadTexture("res/ground_texture.png");
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
    GLCHECK(glUniform1i(texture0, 0 ));
}

void Foot::draw()
{

/*    GLCHECK(glBindTexture(GL_TEXTURE_2D, foot_id));
    GLCHECK(glUseProgram((GLint)program));
    GLCHECK(glActiveTexture(GL_TEXTURE0));
    GLCHECK(glBindTexture(GL_TEXTURE_2D, foot_id));
    GLCHECK(glUniform1i(texture0, 0));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glNormal3f(0.0, 0.0, 1.0);
*/

    glPushMatrix();
      glTranslatef(0,13.5,17);
      glRotatef(120,-1,0,0);
      glRotatef(90,0,0,1);
      glRotatef(10,0,-1,0);
      glEnable(GL_NORMALIZE);

      //face du bas
      glBegin(GL_POLYGON);
      glNormal3f(-1, 0,0.0);
      glVertex3f(0,-1,0);
      glVertex3f(0,1,0);
      glVertex3f(0,3,5);
      glVertex3f(0,0,8);
      glVertex3f(0,-3,5);
      glVertex3f(0,-1,0);
      glEnd();
      //face du haut
      glBegin(GL_POLYGON);
      glNormal3f(1, 0,0.0);
      glVertex3f(1,-1,0);
      glVertex3f(1,1,0);
      glVertex3f(1,3,5);
      glVertex3f(1,0,8);
      glVertex3f(1,-3,5);
      glVertex3f(1,-1,0);
      glEnd();
      //face de la jointure
      glBegin(GL_POLYGON);
      glNormal3f(0,-1,0.0);
      //   glVertexAttrib2f(texcoord0, 0, 0);
      glVertex3f(1,-1,0);
     //    glVertexAttrib2f(texcoord0, 0, 1);
      glVertex3f(1,1,0);
     //    glVertexAttrib2f(texcoord0, 1, 1);
      glVertex3f(0,1,0);
     //    glVertexAttrib2f(texcoord0, 1, 0);
      glVertex3f(0,-1,0);
      glEnd();
      //1ere face
      glBegin(GL_POLYGON);
      glNormal3f(0, 1,-1);
     //   glVertexAttrib2f(texcoord0, 0, 0);
      glVertex3f(1,1,0);
    //  glVertexAttrib2f(texcoord0, 0, 1);
      glVertex3f(1,3,5);
   //    glVertexAttrib2f(texcoord0, 1, 1);
      glVertex3f(0,3,5);
     //  glVertexAttrib2f(texcoord0, 1, 0);
      glVertex3f(0,1,0);
      glEnd();
      //2eme face
      glBegin(GL_POLYGON);
      glNormal3f(0, 1,1);
    //    glVertexAttrib2f(texcoord0, 0, 0);
      glVertex3f(1,3,5);
     //   glVertexAttrib2f(texcoord0, 0, 1);
      glVertex3f(1,0,8);
     //   glVertexAttrib2f(texcoord0, 1, 1);
      glVertex3f(0,0,8);
      //  glVertexAttrib2f(texcoord0, 1, 0);
      glVertex3f(0,3,5);
      glEnd();

      //3eme face
      glBegin(GL_POLYGON);
      glNormal3f(0, -1,1.0);
       // glVertexAttrib2f(texcoord0, 0, 0);
      glVertex3f(1,0,8);
       // glVertexAttrib2f(texcoord0, 0, 1);
      glVertex3f(1,-3,5);
      //  glVertexAttrib2f(texcoord0, 1, 1);
      glVertex3f(0,-3,5);
      //  glVertexAttrib2f(texcoord0, 1, 0);
      glVertex3f(0,0,8);
      glEnd();

      //4eme face
      glBegin(GL_POLYGON);
      glNormal3f(0, -1,-1.0);
     //  glVertexAttrib2f(texcoord0, 0, 0);
      glVertex3f(1,-3,5);
       // glVertexAttrib2f(texcoord0, 0, 1);
      glVertex3f(1,-1,0);
     //   glVertexAttrib2f(texcoord0, 1, 1);
      glVertex3f(0,-1,0);
       // glVertexAttrib2f(texcoord0, 1, 0);
      glVertex3f(0,-3,5);
      glEnd();
      glPopMatrix();

      glDisable(GL_TEXTURE_2D);
}



