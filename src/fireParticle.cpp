#include <fireParticle.h>
#include <glut.h>

FireParticle::FireParticle(qglviewer::Vec pos, qglviewer::Vec vel, double m, double r, double l, double rd, double gr, double bl)
    : life(l),
      red(rd),
      green(gr),
      blue(bl),
      position(pos),
      velocity(vel),
      mass(m),
      size(r)
{
    invMass = (m > 0 ? 1 / m : 0.0);
}

FireParticle::~FireParticle()
{

}


const qglviewer::Vec & FireParticle::getPosition() const
{
    return position;
}

const qglviewer::Vec & FireParticle::getVelocity() const
{
    return velocity;
}

double FireParticle::getMass() const
{
    return mass;
}

double FireParticle::getInvMass() const
{
    return invMass;
}

double FireParticle::getRadius() const
{
    return size;
}

void FireParticle::setPosition(const qglviewer::Vec &pos)
{
    position = pos;
}

void FireParticle::setVelocity(const qglviewer::Vec &vel)
{	
    velocity = vel;
}

void FireParticle::incrPosition(const qglviewer::Vec &pos)
{
    position += pos;
}

void FireParticle::incrVelocity(const qglviewer::Vec &vel)
{
    velocity += vel;
}

void FireParticle::incrLife(int cste)
{
    life += cste;
}

void FireParticle::setLife(int cste)
{
    life = cste;
}

void FireParticle::draw() const
{
    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);
    //to make fire visible in all angles
    glRotatef(10, position.x, position.y, 0);
    glCullFace(GL_FRONT_AND_BACK);
    glColor4d(red, green, blue, 1);
    //glutSolidSphere(size, 2, 2);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3d(position.x+size,position.y,position.z+size); // Nord-Ouest
    glVertex3d(position.x-size,position.y,position.z+size); // Nord-Est
    glVertex3d(position.x+size,position.y,position.z-size); // Sud-Ouest
    glVertex3d(position.x-size,position.y,position.z-size); // Sud-Est
    glEnd();
    glPopMatrix();
}

std::ostream& operator<<(std::ostream& os, const FireParticle& p)
{
    os << "pos (" << p.getPosition() << "), vel (" << p.getVelocity() << ")";
    return os;
}

