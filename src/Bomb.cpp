//
// Created by wouter on 6/17/19.
//

#include "Bomb.h"

namespace GameSpace{
    Bomb::Bomb(int Xpos, int Ypos) : StaticObject(Xpos, Ypos) {

    }

    CollisionEnum GameSpace::Bomb::Collides(const GameSpace::GameObject* object) {
        GameObject::Collides(object);
    }
}


