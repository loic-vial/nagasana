#pragma once

#include <dragonbody.h>
#include <dragonwing.h>
#include <dragontail.h>
#include <fire.h>
#include <big_castle.h>
#include <qglviewer.h>

class Dragon : public Renderable
{
    public:

        void init(Viewer&);

        void draw();

        void draw1();

        void set_castle_to_burn(BigCastle& castle);

    void draw_with_color(bool black);

    void animate();

    void keyPressEvent(QKeyEvent*, Viewer&);

private :

    bool black;
        DragonBody body;

        DragonWing left_wing;

        DragonWing right_wing;

        DragonTail tail;

    Fire fire;

    float max_rotation;

    float min_rotation;

    float wings_rotation;

    bool rotate_backward;

    bool is_flying;

    bool camera_focus;

    qglviewer::Vec position;

    qglviewer::Vec rotation;

    QGLViewer* viewer;

        qglviewer::Vec velocity;

        enum State
        {
            ON_THE_GROUND,
            FLY_HOLD_POSITION,
            FLY_TOWARD_CASTLE,
            FLY_AND_FIRE,
            GET_AROUND_TOWN
        };

        State state;
    bool dark;

    BigCastle* castle_to_burn;

    int delay_before_castle_burn;

    int delay_before_castle_burn2;

    int delay_before_castle_burn3;

    int delay_before_circleing_around;

    double angle_around_castle;
};
