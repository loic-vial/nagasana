#include <glew.h>
#include <terrain.h>
#include <vec3f.h>
#include <glut.h>
#include <QKeyEvent>
#include <iostream>
#include <cstdio>
#include <QGLViewer/qglviewer.h>
#include <stdexcept>
#include <utils.h>
#include <glcheck.h>

using namespace std;

Terrain::Terrain()
{
    height = 500;
    size = 204;
}

void Terrain::init(Viewer&)
{
	h = (float*)calloc(size*size, sizeof(float));
	QImage img = QGLWidget::convertToGLFormat(QImage("res/test.jpeg"));
	img = img.convertToFormat(QImage::Format_RGB888);
	uchar *bits = img.bits();
	int color;
	texture = loadTexture("res/ground_texture2.png");

	for (int i = 0; i < (img.width() * img.height() * 3); i++)
	{
		//std::cout << (int) bits[i] << std::endl;
		if(i%3 == 0){
			color = (int) bits[i];
			float division = (float)color/255.0;
    		h[i/3] = height * division;
    	}
    	//printf("%f\n", h[i]);
	}
}

void Terrain::draw()
{
	int MAP_SIZE = size;
	int match = 20;
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
  //  GLCHECK(glBindTexture(GL_TEXTURE_2D, texture_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glEnable(GL_COLOR_MATERIAL);
    for (int x = 0; x < MAP_SIZE-1; x++) {
      for (int y = 0; y < MAP_SIZE-1; y++) {
        glBegin(GL_QUADS);
          glTexCoord2d(0, 0); glVertex3f(   -2000 + y*match,-2000 + x*match, h[size * y +x] );
          glTexCoord2d(0, 10); glVertex3f( -2000 + y*match,-2000 + (x+1)*match, h[size*y+x+1]);
          glTexCoord2d(10, 10); glVertex3f( -2000 +(y+1)*match,-2000 + (x+1)*match, h[size*(y+1) + x+1]);
          glTexCoord2d(0, 10); glVertex3f( -2000 +(y+1)*match,-2000 + x*match, h[size*(y+1) +x] );
        glEnd();
      }
    }

       
    glPopMatrix();
    glDisable(GL_FOG);
    glDisable(GL_TEXTURE_2D);
}
