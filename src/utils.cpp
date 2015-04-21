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

