//
// Created by wouter on 6/15/19.
//

#include <include/Player.h>

#include "Player.h"

namespace GameSpace{

    void Player::Update(int timeTook) {
        MovingObject::Update(timeTook);
    }

    Player::Player(int beginSpeed) : MovingObject(0,0,std::make_shared<SpeedVector>(0,beginSpeed)) {

    }
}