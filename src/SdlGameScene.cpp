//
// Created by wouter on 6/16/19.
//

#include "SdlGameScene.h"

namespace SDLSpace{
    SdlGameScene::SdlGameScene(std::shared_ptr<SdlDrawEngine> drawEngine, std::shared_ptr<GameSpace::AFactory> factory)
    : GameScene(factory) {

    }

}

