#include <spring.h>
#include <glut.h>

Spring::Spring(const Particle *p1, const Particle *p2, 
               double s, double l0, double d)
    : p1(p1), p2(p2),
      stiffness(s),equilibriumLength(l0), damping(d)
{
}


qglviewer::Vec Spring::getCurrentForce() const
{
    // we compute the force applied on particle 1 by particle 2

    qglviewer::Vec u = p1->getPosition() - p2->getPosition();

    double uNorm = u.normalize();	// u is thereafter normalized!
    if (uNorm < 1.0e-6)
        return qglviewer::Vec();	// null force

    // force due to stiffness only
    qglviewer::Vec sF = -stiffness * (uNorm - equilibriumLength) * u;
    // damping force
    qglviewer::Vec dF = -damping * ((p1->getVelocity() - p2->getVelocity()) * u) * u;

    return sF + dF;
}

const Particle *Spring::getParticle1() const
{
    return p1;
}

const Particle *Spring::getParticle2() const
{
    return p2;
}


void Spring::draw() const
{
    glBegin(GL_LINES);
    qglviewer::Vec pos1 = p1->getPosition();
    qglviewer::Vec pos2 = p2->getPosition();
    glVertex3f(pos1.x, pos1.y, pos1.z);
    glVertex3f(pos2.x, pos2.y, pos2.z);

    // glEnable(GL_TEXTURE_2D);
    //   GLCHECK(glBindTexture(GL_TEXTURE_2D, cone_id));
    //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  //  glColor3ub(255,255,255);

    //   glBindTexture(GL_TEXTURE_2D,cone_id);
  /*  GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL);
    gluQuadricTexture(params,GL_TRUE);
    gluCylinder(params,1.5,2,pos2.y-pos1.y,20,20);
       gluDeleteQuadric(params);*/
    glEnd();
}

