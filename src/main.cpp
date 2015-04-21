#include <qapplication.h>
#include <glew.h>
#include <viewer.h>
#include <dragon.h>
#include <ground.h>

using namespace std;
using namespace qglviewer;

int main(int argc, char** argv)
{
    QApplication application(argc, argv);

	Viewer viewer;


    viewer.addRenderable(new Ground());
    viewer.addRenderable(new Dragon());

    viewer.setWindowTitle("Nagasana");
	viewer.show();

    viewer.startAnimation();

	return application.exec();
}
