//
// Created by wouter on 6/16/19.
//

#include <include/MovingObject.h>

#include "MovingObject.h"

namespace GameSpace{
    void MovingObject::Update(int timeTook) {

    }

    MovingObject::MovingObject(int xPos, int yPos) : GameObject(xPos, yPos) {
        this->speedVector = std::make_shared<SpeedVector>();
    }

    MovingObject::MovingObject(
            int xPos,
            int yPos,
            std::shared_ptr<SpeedVector> speedVector)
            : GameObject(xPos,yPos) {
        this->speedVector = speedVector;
    }
}


