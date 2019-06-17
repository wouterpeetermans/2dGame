//
// Created by wouter on 6/16/19.
//

#include <include/MovingObject.h>

#include "MovingObject.h"

namespace GameSpace{
    void MovingObject::Update(int timeTook) {
        this->yPos += speedVector->ySpeed()*timeTook;
        this->xPos += speedVector->xSpeed()*timeTook;
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

    CollisionEnum MovingObject::Collides(const GameObject* object) {
        if(GameObject::Collides(object) == EVENT){
            return CRASH;
        }
        return NONE;
    }
}


