//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_SDLBACKGROUND1_H
#define INC_2DGAME_SDLBACKGROUND1_H


#include "SdlDrawEngine.h"
#include "Background1.h"

namespace SDLSpace{
class SdlBackground1 : public GameSpace::Background1 {
public:
    SdlBackground1(std::shared_ptr<GameObject> player, std::shared_ptr<SdlDrawEngine> drawEngine);
    ~SdlBackground1() override;


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
