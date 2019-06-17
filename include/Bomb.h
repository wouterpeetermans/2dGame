//
// Created by wouter on 6/17/19.
//

#ifndef INC_2DGAME_BOMB_H
#define INC_2DGAME_BOMB_H


#include "StaticObject.h"

namespace GameSpace {
    class Bomb : public StaticObject {
    public:
        Bomb(int Xpos, int Ypos);

        CollisionEnum Collides(const GameObject* object) override;
    };
}


#endif //INC_2DGAME_BOMB_H
