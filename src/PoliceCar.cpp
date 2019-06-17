//
// Created by wouter on 6/17/19.
//


#include "PoliceCar.h"

namespace GameSpace{

    PoliceCar::PoliceCar(int xPos, int yPos, int speed, std::shared_ptr<std::list<std::shared_ptr<GameObject>>> objectList,
                             std::shared_ptr<AFactory> factory)
    : MovingObject(xPos,yPos,std::make_shared<SpeedVector>(0,speed)) {
        this->objectList = objectList;
        this->factory = factory;
        this->setHeight(2100);
        this->setWidth(900);
        this->nextDropPoint = yPos + rand()%5000;
    }

    void PoliceCar::Update(int timeTook) {
        MovingObject::Update(timeTook);
        if(yPos >= nextDropPoint){
            nextDropPoint = yPos + rand()%5000;
            objectList->push_back(factory->CreateBomb(xPos,yPos));
        }
        //todo make this one drop some stuff
    }
}