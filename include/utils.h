#pragma once

#include <qglviewer.h>

using namespace std;

GLuint loadTexture(const char* filename);


void MakeShadowMatrix(GLfloat points_plan[3][3], GLfloat lightPos[4], GLfloat destMat[4][4]) ;

void Normale(float v[3][3], float out[3]);

void Vecteur_Unite(float vector[3]);
