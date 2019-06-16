//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_SDLBACKGROUND1_H
#define INC_2DGAME_SDLBACKGROUND1_H


#include "SdlDrawEngine.h"
#include "Road.h"

namespace SDLSpace{
class SdlRoad : public GameSpace::Road {
public:
    SdlRoad(std::shared_ptr<GameObject> player, std::shared_ptr<SdlDrawEngine> drawEngine);
    ~SdlRoad() override;


    void Update(int TimeTook) override;

private:
    void draw(SDL_Renderer* renderer);
    std::shared_ptr<SdlDrawEngine> drawEngine;
    SDL_Texture* sourceTexture;
    SDL_Texture* totalTexture;
    SDL_Rect srcRect;
    SDL_Rect posRect;

};
}



#endif //INC_2DGAME_SDLBACKGROUND1_H
