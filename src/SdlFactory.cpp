//
// Created by wouter on 3/11/19.
//


#include "SdlRoad.h"
#include "SdlCar.h"
#include "SdlFactory.h"

#include "SdlFactory.h"

namespace SDLSpace {
    std::shared_ptr<GameSpace::GameObject> SdlFactory::CreateCar(int Xpos, int Ypos) {
        return std::make_shared<SdlCar>(drawEngine,Xpos,Ypos);
    }

    SdlFactory::~SdlFactory() {

    }

    SdlFactory::SdlFactory() {
        this->drawEngine = std::make_shared<SdlDrawEngine>();
    }

    std::shared_ptr<GameSpace::DrawEngine> SdlFactory::GetDrawEngine() {
        return drawEngine;
    }

    std::shared_ptr<GameSpace::GameObject> SdlFactory::CreateBackground1(std::shared_ptr<GameSpace::GameObject> player) {
        return std::make_shared<SdlRoad>(player,drawEngine);
    }

//    std::shared_ptr<GameSpace::DrawEngine> SdlFactory::CreateGameLoop() {
//        return std::allocate_shared<GameSpace::DrawEngine>(drawEngine);
//    }
}


