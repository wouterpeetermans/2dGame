//
// Created by wouter on 3/4/19.
//

#include <include/MiniVan.h>

#include "MiniVan.h"

namespace GameSpace{

    void MiniVan::Update(int timeTook) {
        MovingObject::Update(timeTook);
    }

    MiniVan::~MiniVan() {

    }

    MiniVan::MiniVan(int Xpos, int Ypos, int speed)
    : MovingObject(Xpos, Ypos, std::make_shared<SpeedVector>(0,speed)) {

    }

}


