#include <qapplication.h>
#include "viewer.h"
#include "dragon.h"

int main(int argc, char** argv)
{
    QApplication application(argc, argv);

	Viewer viewer;

    viewer.addRenderable(new Dragon());

    viewer.setWindowTitle("Nagasana");
	viewer.show();

	return application.exec();
}
