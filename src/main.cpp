#include <qapplication.h>
#include <glew.h>
#include <viewer.h>
#include <dragon.h>
#include <ground.h>
#include <skybox.h>
#include <big_castle.h>

using namespace std;
using namespace qglviewer;

int main(int argc, char** argv)
{
    QApplication application(argc, argv);

    Viewer viewer;

    glEnable(GL_LIGHT0);
    GLfloat ambient[] = {0.15f,0.15f,0.15f,1.0f};
    GLfloat diffuse[] = {0.1f,0.1f,0.1f,1.0f};
    GLfloat light0_position [] = {0.0f, 0.0f, 10.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);


    viewer.addRenderable(new Skybox());
    viewer.addRenderable(new Ground());
    viewer.addRenderable(new BigCastle());
    viewer.addRenderable(new Dragon());


    viewer.setWindowTitle("Nagasana");
    viewer.show();

    viewer.startAnimation();

    return application.exec();
}
