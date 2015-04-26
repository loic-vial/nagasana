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


    viewer.addRenderable(new Skybox());
    viewer.addRenderable(new Ground());
    viewer.addRenderable(new BigCastle());
    viewer.addRenderable(new Dragon());


    viewer.setWindowTitle("Nagasana");
    viewer.show();

    viewer.startAnimation();

    return application.exec();
}
