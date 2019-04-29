//
// Created by wouter on 3/11/19.
//

#include <include/SDLCar.h>
#include <include/SDLFactory.h>

#include "SDLFactory.h"

namespace SDLSpace {
    std::shared_ptr<GameSpace::GameObject> SDLFactory::CreateCar() {
        return std::shared_ptr<GameSpace::GameObject>(new SDLCar(drawEngine));
    }

    SDLFactory::~SDLFactory() {

    }

    SDLFactory::SDLFactory() {
        this->drawEngine = std::make_shared<SDLDrawEngine>(SDLDrawEngine());
    }

//    std::shared_ptr<GameSpace::IGameLoopController> SDLFactory::CreateGameLoop() {
//        return std::allocate_shared<GameSpace::IGameLoopController>(drawEngine);
//    }
}


