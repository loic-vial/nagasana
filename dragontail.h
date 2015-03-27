#pragma once

#include "renderable.h"
#include "spring.h"
#include "particle.h"

class DragonTail : public Renderable
{
    public :

        DragonTail();

        void init(Viewer&);

        void draw();

        void animate();

    private :

        std::vector<Particle*> particles;

        std::vector<Spring*> springs;
};

