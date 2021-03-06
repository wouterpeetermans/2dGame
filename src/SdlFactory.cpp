//
// Created by wouter on 3/11/19.
//


#include "SdlRoad.h"
#include "SdlPlayer.h"
#include "SdlMinivan.h"
#include "SdlFactory.h"
#include "SdlGameScene.h"
#include "SdlPoliceCar.h"
#include "SdlBomb.h"


namespace SDLSpace {
    std::shared_ptr<GameSpace::Player> SdlFactory::CreatePlayer(int beginSpeed) {
        return std::make_shared<SdlPlayer>(drawEngine,beginSpeed);
    }

    SdlFactory::~SdlFactory() {

    }

    SdlFactory::SdlFactory() {
        this->drawEngine = std::make_shared<SdlDrawEngine>();
    }

    std::shared_ptr<GameSpace::DrawEngine> SdlFactory::GetDrawEngine() {
        return drawEngine;
    }

    std::shared_ptr<GameSpace::GameObject> SdlFactory::CreateRoad(std::shared_ptr<GameSpace::GameObject> player) {
        return std::make_shared<SdlRoad>(player,drawEngine);
    }

    std::shared_ptr<GameSpace::GameObject> SdlFactory::CreateMiniVan(int xPos, int yPos, int speed) {
        return std::make_shared<SdlMinivan>(drawEngine, xPos,yPos,speed);
    }

    std::shared_ptr<GameSpace::Scene> SdlFactory::CreateGameScene(std::shared_ptr<AFactory> factory) {
        return std::make_shared<SdlGameScene>(drawEngine, factory);
    }

    std::shared_ptr<GameSpace::GameObject> SdlFactory::CreatePoliceCar(
            int xPos,
            int yPos,
            int speed,
            std::shared_ptr<std::list<std::shared_ptr<GameSpace::GameObject>>> objectList,
            std::shared_ptr<AFactory> factory) {
        return std::make_shared<SdlPoliceCar>(drawEngine, xPos, yPos, speed, objectList, factory);
    }

    std::shared_ptr<GameSpace::GameObject> SdlFactory::CreateBomb(int xPos, int yPos) {
        return std::make_shared<SdlBomb>(drawEngine,xPos,yPos);
    }

//    std::shared_ptr<GameSpace::DrawEngine> SdlFactory::CreateGameLoop() {
//        return std::allocate_shared<GameSpace::DrawEngine>(drawEngine);
//    }
}


