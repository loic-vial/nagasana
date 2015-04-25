#pragma once

#include <qglviewer.h>

GLuint loadTexture(const char* filename);

void renderCylinder(float x1, float y1, float z1, float x2, float y2, float z2, float radius1, float radius2, int subdivisions, GLUquadricObj* quadric);

void MakeShadowMatrix(GLfloat points_plan[3][3], GLfloat lightPos[4], GLfloat destMat[4][4]) ;

void Normale(float v[3][3], float out[3]);

void Vecteur_Unite(float vector[3]);

void renderCylinder(qglviewer::Vec p1, qglviewer::Vec p2, float radius1, float radius2, int subdivisions, GLUquadricObj* quadric);

