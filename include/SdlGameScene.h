//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_SDLGAMESCENE_H
#define INC_2DGAME_SDLGAMESCENE_H

#include "GameScene.h"
#include "SdlDrawEngine.h"


namespace SDLSpace{
class SdlGameScene : public GameSpace::GameScene {
public:
    SdlGameScene(std::shared_ptr<SdlDrawEngine> drawEngine, std::shared_ptr<GameSpace::AFactory> factory);
};
}




#endif //INC_2DGAME_SDLGAMESCENE_H
