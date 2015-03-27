#include <qapplication.h>
#include "viewer.h"
#include "dragon.h"
#include "cylinder.h"

int main(int argc, char** argv)
{
    QApplication application(argc, argv);

	Viewer viewer;

   viewer.addRenderable(new Dragon());
   // viewer.addRenderable(new Cylinder(5,2,3, 1));

    viewer.setWindowTitle("Nagasana");
	viewer.show();

	return application.exec();
}
