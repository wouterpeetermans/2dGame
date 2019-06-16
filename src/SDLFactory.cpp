//
// Created by wouter on 3/11/19.
//


#include "SDLBackground1.h"
#include "SDLCar.h"
#include "SDLFactory.h"

#include "SDLFactory.h"

namespace SDLSpace {
    std::shared_ptr<GameSpace::GameObject> SDLFactory::CreateCar(int Xpos, int Ypos) {
        return std::make_shared<SDLCar>(drawEngine,Xpos,Ypos);
    }

    SDLFactory::~SDLFactory() {

    }

    SDLFactory::SDLFactory() {
        this->drawEngine = std::make_shared<SDLDrawEngine>();
    }

    std::shared_ptr<GameSpace::DrawEngine> SDLFactory::GetDrawEngine() {
        return drawEngine;
    }

    std::shared_ptr<GameSpace::GameObject> SDLFactory::CreateBackground1(std::shared_ptr<GameSpace::GameObject> player) {
        return std::make_shared<SDLBackground1>(player,drawEngine);
    }

//    std::shared_ptr<GameSpace::DrawEngine> SDLFactory::CreateGameLoop() {
//        return std::allocate_shared<GameSpace::DrawEngine>(drawEngine);
//    }
}


