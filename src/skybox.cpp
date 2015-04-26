#include <glew.h>
#include <skybox.h>
#include <glut.h>
#include <QKeyEvent>
#include <iostream>
#include <cstdio>
#include <QGLViewer/qglviewer.h>
#include <stdexcept>
#include <utils.h>
#include <glcheck.h>

using namespace std;

Skybox::Skybox()
{

}

void Skybox::init(Viewer&)
{

    texture_back = loadTexture("res/blood_sport512_back.jpg");
    texture_front = loadTexture("res/blood_sport512_front.jpg");
    texture_top = loadTexture("res/blood_sport512_top.jpg");
    texture_left = loadTexture("res/blood_sport512_left.jpg");
    texture_right = loadTexture("res/blood_sport512_right.jpg");
    texture_sky = loadTexture("res/s3.jpg");
}

void Skybox::draw()
{
    // Store the current matrix
    glPushMatrix();


    glEnable(GL_LIGHT0);
    GLfloat ambient[] = {0.4f,0.4f,0.4f,1.0f};
    //GLfloat diffuse[] = {0.9f,0.3f,0.3f,1.0f};
    GLfloat light0_position [] = {20.0f, 100.0f, 100.0f, 0.0f};
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
   // glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
    glLightfv(GL_LIGHT0,GL_POSITION,light0_position);



    /*
    glColor4f(1,1,1,1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_sky);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricTexture(quadric, GL_TRUE);
    gluSphere(quadric, 1000, 10, 10);
    glDisable(GL_TEXTURE_2D);
*/

    glEnable(GL_FOG) ;
    GLfloat fogcolor[4] = {0.2, 0.2, 0.2, 1} ;
    GLint fogmode = GL_EXP ;
    glFogi (GL_FOG_MODE, fogmode) ;
    glFogfv(GL_FOG_COLOR, fogcolor) ;
    glFogf(GL_FOG_DENSITY, 0.0003) ;
    glFogf(GL_FOG_START, 1.0) ;
    glFogf(GL_FOG_END, 10.0) ;
glFogf(GL_FOG_COORD_SRC,GL_FRAGMENT_DEPTH);

    // Enable/Disable features
    glPushAttrib(GL_ENABLE_BIT);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);

    int size = 2000;

    // Just in case we set all vertices to white.
    glColor4f(1,1,1,1);

    // Render the back quad

    glBindTexture(GL_TEXTURE_2D, texture_back);
    // GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_back));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f( -size, -size, 0 );
    glTexCoord2f(0, 1); glVertex3f( -size, -size,  size );
    glTexCoord2f(1, 1); glVertex3f(  size, -size,  size );
    glTexCoord2f(1, 0); glVertex3f(  size, -size, 0 );
    glEnd();

    // Render the left quad
    glBindTexture(GL_TEXTURE_2D, texture_left);
    // GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_left));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex3f(  size, -size,  size );
    glTexCoord2f(0, 0); glVertex3f(  size, -size,   0 );
    glTexCoord2f(1, 0); glVertex3f(  size,  size, 	0 );
    glTexCoord2f(1, 1); glVertex3f(  size,  size,  size );
    glEnd();

    // Render the top quad
    glBindTexture(GL_TEXTURE_2D, texture_top);
    //GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_top));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f( -size, -size,  size );
    glTexCoord2f(0, 1); glVertex3f(  size, -size,  size );
    glTexCoord2f(1, 1); glVertex3f(  size,  size,  size );
    glTexCoord2f(1, 0); glVertex3f( -size,  size,  size );

    glEnd();

    // Render the right quad
    glBindTexture(GL_TEXTURE_2D, texture_right);
    //   GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_right));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0); glVertex3f( -size, -size, 0 );
    glTexCoord2f(1, 1); glVertex3f( -size, -size,  size );
    glTexCoord2f(0, 1); glVertex3f( -size,  size,  size );
    glTexCoord2f(0, 0); glVertex3f( -size,  size, 0 );
    glEnd();

    // Render the front quad
    glBindTexture(GL_TEXTURE_2D, texture_front);
    // GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_front));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0); glVertex3f( -size,  size, 0 );
    glTexCoord2f(1, 1); glVertex3f( -size,  size,  size );
    glTexCoord2f(0, 1); glVertex3f(  size,  size,  size );
    glTexCoord2f(0, 0); glVertex3f(  size,  size, 0 );
    glEnd();

    /*
    // Render the bottom quad
    glBindTexture(GL_TEXTURE_2D, _skybox[5]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -size, -size, -size );
        glTexCoord2f(0, 1); glVertex3f( -size, -size,  size );
        glTexCoord2f(1, 1); glVertex3f(  size, -size,  size );
        glTexCoord2f(1, 0); glVertex3f(  size, -size, -size );
    glEnd();*/

    // Restore enable bits and matrix
    glPopAttrib();
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}
