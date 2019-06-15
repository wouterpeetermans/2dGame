//
// Created by wouter on 6/15/19.
//

#include <include/Background1.h>

#include "Background1.h"

namespace GameSpace{
    void Background1::Update(int timeTook) {

    }

    Background1::Background1(std::shared_ptr<GameObject> player) : GameObject(0,0) {
        this->player = player;
    }
}