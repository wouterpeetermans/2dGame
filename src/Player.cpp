//
// Created by wouter on 6/15/19.
//

#include <include/Player.h>

#include "Player.h"

namespace GameSpace{

    void Player::Update(int timeTook) {
        MovingObject::Update(timeTook);
        if(health <= 0){
            this->setDestroyed();
        }
        this->speedVector->setySpeed(10+(this->yPos/100000));
    }

    Player::Player(int beginSpeed) : MovingObject(0,0,std::make_shared<SpeedVector>(0,beginSpeed)) {
        this->health = 100;
        this->setHeight(2100);
        this->setWidth(900);
    }

    void Player::DetectCollisions(std::shared_ptr<std::list<std::shared_ptr<GameObject>>> coliderList) {
        for(std::shared_ptr<GameObject> object : *coliderList){
            CollisionEnum result = object->Collides(this);
            switch(result){
                case NONE:
                    break;
                case CRASH:
                    this->setDestroyed();
                    break;
                case DAMAGE:
                    this->health -= 25;
                    break;
                case POWER_UP:
                    this->health += 25;
                    break;
                case SOLID:
                    break;
                default:
                    break;
            }
        }
    }
}