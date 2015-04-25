#include <glew.h>
#include <utils.h>
#include <QGLViewer/qglviewer.h>
#include <glcheck.h>

using namespace std;

GLuint loadTexture(const char* filename)
{
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    QImage img = QGLWidget::convertToGLFormat(QImage(filename));
    GLCHECK(glBindTexture(GL_TEXTURE_2D, id));
    GLCHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width(), img.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img.bits()));
    GLCHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GLCHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    glDisable(GL_TEXTURE_2D);
    return id;
}

void renderCylinder(float x1, float y1, float z1, float x2,float y2, float z2, float radius1, float radius2, int subdivisions, GLUquadricObj *quadric)
{
    float vx = x2-x1;
    float vy = y2-y1;
    float vz = z2-z1;

    //handle the degenerate case of z1 == z2 with an approximation
    if(vz == 0)
        vz = .0001;

    float v = sqrt( vx*vx + vy*vy + vz*vz );
    float ax = 57.2957795*acos( vz/v );
    if ( vz < 0.0 )
        ax = -ax;
    float rx = -vy*vz;
    float ry = vx*vz;
    glPushMatrix();

    //draw the cylinder body
    glTranslatef( x1,y1,z1 );
    glRotatef(ax, rx, ry, 0.0);
    gluQuadricOrientation(quadric,GLU_OUTSIDE);
    gluCylinder(quadric, radius1, radius2, v, subdivisions, 1);

    //draw the first cap
    gluQuadricOrientation(quadric,GLU_INSIDE);
    gluDisk( quadric, 0.0, radius1, subdivisions, 1);
    glTranslatef( 0,0,v );

    //draw the second cap
    gluQuadricOrientation(quadric,GLU_OUTSIDE);
    gluDisk( quadric, 0.0, radius2, subdivisions, 1);
    glPopMatrix();
}

void renderCylinder(qglviewer::Vec p1, qglviewer::Vec p2, float radius1, float radius2, int subdivisions, GLUquadricObj* quadric)
{
    renderCylinder(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, radius1, radius2, subdivisions, quadric);
}
