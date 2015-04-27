#pragma once

#include <renderable.h>
#include <spring.h>
#include <sphere.h>

class DragonTail : public Renderable
{
    public :

        DragonTail();

        void init(Viewer&);

        void draw();

        void animate();

        bool black;

    private :

        std::vector<Sphere*> particles;

        std::vector<Spring*> springs;

        GLuint scale_id;
};

