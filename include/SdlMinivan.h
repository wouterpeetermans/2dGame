//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_SDLMINIVAN_H
#define INC_2DGAME_SDLMINIVAN_H


#include <SDL2/SDL.h>
#include "MiniVan.h"
#include "SdlDrawEngine.h"

namespace SDLSpace {
    class SdlMinivan : public GameSpace::MiniVan {
    public:
        SdlMinivan(std::shared_ptr<SdlDrawEngine> drawEngine, int xPos, int yPos, int speed);
        void Update(int timeTook) override;
        ~SdlMinivan() override;

    private:
        void draw(SDL_Renderer* renderer);
        std::shared_ptr<SdlDrawEngine> drawEngine;
        SDL_Rect destinationRect;
        SDL_Texture* vanTexture;
    };
}


#endif //INC_2DGAME_SDLMINIVAN_H
