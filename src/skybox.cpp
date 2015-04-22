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
    
}

void Skybox::draw()
{
	// Store the current matrix
    glPushMatrix();
 
 	//glCullFace(GL_FRONT_AND_BACK);
    // Enable/Disable features
    glPushAttrib(GL_ENABLE_BIT);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);
 
    // Just in case we set all vertices to white.
    glColor4f(1,1,1,1);
 
    // Render the back quad
    GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_back));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
    	glTexCoord2f(0, 0); glVertex3f( -1000, -1000, 0 );
        glTexCoord2f(0, 1); glVertex3f( -1000, -1000,  1000 );
        glTexCoord2f(1, 1); glVertex3f(  1000, -1000,  1000 );
        glTexCoord2f(1, 0); glVertex3f(  1000, -1000, 0 );
    glEnd();
 	
    // Render the left quad
    GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_left));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f(  1000, -1000,  1000 );
        glTexCoord2f(0, 0); glVertex3f(  1000, -1000,   0 );
        glTexCoord2f(1, 0); glVertex3f(  1000,  1000, 	0 );
        glTexCoord2f(1, 1); glVertex3f(  1000,  1000,  1000 );
    glEnd();
 	
    // Render the top quad
    GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_top));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -1000, -1000,  1000 );
        glTexCoord2f(0, 1); glVertex3f(  1000, -1000,  1000 );
        glTexCoord2f(1, 1); glVertex3f(  1000,  1000,  1000 );
        glTexCoord2f(1, 0); glVertex3f( -1000,  1000,  1000 );
 
    glEnd();
 
    // Render the right quad
    GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_right));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
        glTexCoord2f(1, 0); glVertex3f( -1000, -1000, 0 );
        glTexCoord2f(1, 1); glVertex3f( -1000, -1000,  1000 );
        glTexCoord2f(0, 1); glVertex3f( -1000,  1000,  1000 );
        glTexCoord2f(0, 0); glVertex3f( -1000,  1000, 0 );
    glEnd();
 
    // Render the front quad
    GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_front));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
        glTexCoord2f(1, 0); glVertex3f( -1000,  1000, 0 );
        glTexCoord2f(1, 1); glVertex3f( -1000,  1000,  1000 );
        glTexCoord2f(0, 1); glVertex3f(  1000,  1000,  1000 );
        glTexCoord2f(0, 0); glVertex3f(  1000,  1000, 0 );
    glEnd();
 
    /*
    // Render the bottom quad
    glBindTexture(GL_TEXTURE_2D, _skybox[5]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -1000, -1000, -1000 );
        glTexCoord2f(0, 1); glVertex3f( -1000, -1000,  1000 );
        glTexCoord2f(1, 1); glVertex3f(  1000, -1000,  1000 );
        glTexCoord2f(1, 0); glVertex3f(  1000, -1000, -1000 );
    glEnd();*/
 
    // Restore enable bits and matrix
    glPopAttrib();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
