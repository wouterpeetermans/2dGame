//
// Created by wouter on 6/17/19.
//

#ifndef INC_2DGAME_SDLBOMB_H
#define INC_2DGAME_SDLBOMB_H


#include "Bomb.h"
#include "SdlDrawEngine.h"

namespace SDLSpace {
    class SdlBomb : public GameSpace::Bomb {
    public:
        SdlBomb(std::shared_ptr<SdlDrawEngine> drawEngine, int Xpos, int Ypos);
        void Update(int timeTook);
        ~SdlBomb() override;

    private:
        void draw(SDL_Renderer* renderer);
        std::shared_ptr<SdlDrawEngine> drawEngine;
        SDL_Rect destinationRect;
        SDL_Rect sourceRect;
        SDL_Texture* bombTexture;
    };
}


#endif //INC_2DGAME_SDLBOMB_H
