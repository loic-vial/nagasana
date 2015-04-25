#pragma once

#include <qglviewer.h>

GLuint loadTexture(const char* filename);

void renderCylinder(float x1, float y1, float z1, float x2, float y2, float z2, float radius1, float radius2, int subdivisions, GLUquadricObj* quadric);

void renderCylinder(qglviewer::Vec p1, qglviewer::Vec p2, float radius1, float radius2, int subdivisions, GLUquadricObj* quadric);
