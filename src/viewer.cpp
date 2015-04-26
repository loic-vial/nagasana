#include <QKeyEvent>
#include <glut.h>
#include <viewer.h>
#include <renderable.h>

using namespace std;
using qglviewer::Vec;

Viewer::~Viewer()
{
    list<Renderable *>::iterator it;
    for (it = renderableList.begin(); it != renderableList.end(); ++it)
    {
        delete(*it);
    }
    renderableList.clear();
}

void Viewer::addRenderable(Renderable *r)
{
    renderableList.push_back(r);
}

void Viewer::init()
{
    int dum = 0;
    glutInit(&dum, NULL);

    restoreStateFromFile();

    //camera()->setPosition(Vec(-150, 200, 70));
    //camera()->setUpVector(Vec(0, 0, 1));
    //camera()->lookAt(Vec(0, 0, 0));

    toogleWireframe = false;
    toogleLight = true;
    help();

    if (toogleLight == true) glEnable(GL_LIGHTING);
    else glDisable(GL_LIGHTING);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    setSceneRadius(10000);

    list<Renderable *>::iterator it;
    for (it = renderableList.begin(); it != renderableList.end(); ++it)
    {
        (*it)->init(*this);
    }
}


void Viewer::draw()
{
    list<Renderable *>::iterator it;
    for(it = renderableList.begin(); it != renderableList.end(); ++it)
    {
        (*it)->draw();
    }
}


void Viewer::animate()
{
    for(list<Renderable *>::iterator it = renderableList.begin(); it != renderableList.end(); ++it)
    {
        (*it)->animate();
    }
}


void Viewer::mouseMoveEvent(QMouseEvent *e)
{
    for(list<Renderable*>::iterator it = renderableList.begin(); it != renderableList.end(); ++it)
    {
        (*it)->mouseMoveEvent(e, *this);
    }

    QGLViewer::mouseMoveEvent(e);
    updateGL();
}

void Viewer::keyPressEvent(QKeyEvent *e)
{
    const Qt::KeyboardModifiers modifiers = e->modifiers();

    for(list<Renderable*>::iterator it = renderableList.begin(); it != renderableList.end(); ++it)
    {
        (*it)->keyPressEvent(e, *this);
    }

    if ((e->key()==Qt::Key_W) && (modifiers==Qt::NoButton))
    {
        toogleWireframe = !toogleWireframe;
        if (toogleWireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else if ((e->key()==Qt::Key_L) && (modifiers==Qt::NoButton))
    {
        toogleLight = !toogleLight;
        if (toogleLight == true) glEnable(GL_LIGHTING);
        else glDisable(GL_LIGHTING);
    }
    else
    {
        QGLViewer::keyPressEvent(e);
    }
    updateGL();
}


QString Viewer::helpString() const
{
    QString text("<h2>V i e w e r</h2>");
    text += "Use the mouse to move the camera around the object. ";
    text += "You can respectively revolve around, zoom and translate with the three mouse buttons. ";
    text += "Left and middle buttons pressed together rotate around the camera view direction axis<br><br>";
    text += "Pressing <b>Alt</b> and one of the function keys (<b>F1</b>..<b>F12</b>) defines a camera keyFrame. ";
    text += "Simply press the function key again to restore it. Several keyFrames define a ";
    text += "camera path. Paths are saved when you quit the application and restored at next start.<br><br>";
    text += "Press <b>F</b> to display the frame rate, <b>A</b> for the world axis, ";
    text += "<b>Alt+Return</b> for full screen mode and <b>Control+S</b> to save a snapshot. ";
    text += "See the <b>Keyboard</b> tab in this window for a complete shortcut list.<br><br>";
    text += "Double clicks automates single click actions: A left button double click aligns the closer axis with the camera (if close enough). ";
    text += "A middle button double click fits the zoom of the camera and the right button re-centers the scene.<br><br>";
    text += "A left button double click while holding right button pressed defines the camera <i>Revolve Around Point</i>. ";
    text += "See the <b>Mouse</b> tab and the documentation web pages for details.<br><br>";
    text += "Press <b>Escape</b> to exit the viewer.";
    return text;
}

