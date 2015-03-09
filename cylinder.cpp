#include "cylinder.h"
#include "math.h"

void Cylinder::init(Viewer&)
{

}

void Cylinder::draw()
{
    glPushMatrix();

    drawImmediate();

    glPopMatrix();
}



void Cylinder::drawImmediate()
{
    float radius = 2;
    int num_segments = 1000;
    float depth = -7;

    glEnable(GL_NORMALIZE);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
        glVertex3f(radius * cosf(theta), radius * sinf(theta), 0);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
        glVertex3f(radius * cosf(theta), radius * sinf(theta), depth);
    }
    glEnd();

    float ax, ay, az;
    float bx, by, bz;
    for(int ii = 0; ii < num_segments; ii++)
    {
        glBegin(GL_POLYGON);
        float theta1 = 2.0f * 3.1415926f * float(ii) / float(num_segments);
        float theta2 = 2.0f * 3.1415926f * float(ii + 1) / float(num_segments);

        ax = 0;
        ay = 0;
        az = depth;

        bx = radius * cosf(theta2) - radius * cosf(theta1);
        by = radius * sinf(theta2) - radius * sinf(theta1);
        bz = depth;

        glNormal3f(ay * bz - az * by, az * bx - ax * bz, ax * by - ay * bx);


        glVertex3f(radius * cosf(theta1), radius * sinf(theta1), 0);
        glVertex3f(radius * cosf(theta1), radius * sinf(theta1), depth);
        glVertex3f(radius * cosf(theta2), radius * sinf(theta2), depth);
        glVertex3f(radius * cosf(theta2), radius * sinf(theta2), 0);
        glEnd();
    }

}
