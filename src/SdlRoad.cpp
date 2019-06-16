//
// Created by wouter on 6/16/19.
//

#include <include/SdlRoad.h>

#include "SdlRoad.h"

namespace SDLSpace {


    void SdlRoad::Update(int timeTook) {
        GameSpace::Road::Update(timeTook);
        this->srcRect.y = 2048 -((player->getYpos() - 2000) / 5) % 2048;
        draw(drawEngine->getRenderer());
    }

    SdlRoad::SdlRoad(
            std::shared_ptr<GameObject> player,
            std::shared_ptr<SdlDrawEngine> drawEngine)
            : GameSpace::Road(player) {
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

    SdlRoad::~SdlRoad() {
        SDL_DestroyTexture(sourceTexture);
        SDL_DestroyTexture(totalTexture);
    }

    void SdlRoad::draw(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer, totalTexture, &srcRect, &posRect);
    }

}

