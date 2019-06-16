//
// Created by wouter on 6/16/19.
//

#include <include/SdlBackground1.h>

#include "SdlBackground1.h"

namespace SDLSpace {


    void SdlBackground1::Update(int timeTook) {
        GameSpace::Background1::Update(timeTook);
        this->srcRect.y = 2048 -((player->getYpos() - 2000) / 5) % 2048;
        draw(drawEngine->getRenderer());
    }

    SdlBackground1::SdlBackground1(
            std::shared_ptr<GameObject> player,
            std::shared_ptr<SdlDrawEngine> drawEngine)
            : GameSpace::Background1(player) {
        this->drawEngine = drawEngine;
        this->sourceTexture = drawEngine->LoadTexture("sprites/RoadTexture.png");
        this->totalTexture = drawEngine->CreateTexture(1500, 8192);
        SDL_Renderer* renderer = this->drawEngine->getRenderer();
        SDL_SetRenderTarget(renderer, totalTexture);
        SDL_RenderClear(renderer);
        SDL_Rect tempsrcRect;
        tempsrcRect.w = 1500;
        tempsrcRect.h = 2048;
        tempsrcRect.x = 0;
        tempsrcRect.y = 0;
        SDL_Rect tempDestRect;
        tempDestRect.w = 1500;
        tempDestRect.h = 2048;
        tempDestRect.x = 0;
        for (int i = 0; i < 4; i++) {
            tempDestRect.y = i * 2048;
            SDL_RenderCopy(renderer, sourceTexture, &tempsrcRect, &tempDestRect);
        }

        drawEngine->resetRendererTexture();

        this->srcRect.h = 6144;
        this->srcRect.w = 1500;
        this->srcRect.x = 0;
        this->srcRect.y = 0;
        this->posRect.h = 6144;
        this->posRect.w = 1500;
        this->posRect.x = 0;
        this->posRect.y = 0;
    }

    SdlBackground1::~SdlBackground1() {
        SDL_DestroyTexture(sourceTexture);
        SDL_DestroyTexture(totalTexture);
    }

    void SdlBackground1::draw(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer, totalTexture, &srcRect, &posRect);
    }

}

