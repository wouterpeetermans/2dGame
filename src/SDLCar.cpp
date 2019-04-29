//
// Created by wouter on 3/25/19.
//



#include <include/SDLCar.h>

#include "SDLCar.h"

namespace SDLSpace {

    SDLCar::SDLCar(std::shared_ptr<SDLDrawEngine> drawEngine) {
        this->drawEngine = drawEngine;
    }

    SDLCar::~SDLCar() {

    }

    void SDLCar::Draw() {

    }
}