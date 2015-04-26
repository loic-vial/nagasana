#pragma once

#include <renderable.h>
#include <vector>
#include <tree.h>

class Forest : public Renderable
{
    public :

        void init(Viewer& v);

        void draw();

    private :

        int trees_nb;

        std::vector<Tree*> trees;

};
