//
// Created by wouter on 6/16/19.
//

#include <include/SDLBackground1.h>

#include "SDLBackground1.h"

namespace SDLSpace{
    void SDLBackground1::DetectCollisions(
            std::shared_ptr<std::list<std::shared_ptr<GameSpace::GameObject>>> ColliderList) {

    }

    bool SDLBackground1::HasCollision(std::shared_ptr<GameSpace::GameObject> object) {
        return false;
    }

    void SDLBackground1::Update(int timeTook) {
        GameSpace::Background1::Update(timeTook);
        this->srcRect.x = (player->getXpos() - 2000) % 512;
    }

    SDLBackground1::SDLBackground1(std::shared_ptr<GameObject> player, std::shared_ptr<SDLDrawEngine> drawEngine)
            : GameSpace::Background1(player) {
        this->drawEngine = drawEngine;
        this->sourceTexture = drawEngine->LoadTexture("sprites/RoadTexture.png");
        this->totalTexture = drawEngine->CreateTexture(1500,6144);
        SDL_Renderer* renderer = this->drawEngine->getRenderer();
        SDL_SetRenderTarget(renderer,totalTexture);
        SDL_Rect tempsrcRect;
        tempsrcRect.w = 1500;
        tempsrcRect.h = 2048;
        SDL_Rect tempDestRect;
        tempDestRect.w = 1500;
        tempDestRect.h = 2048;
        for (int i = 0; i < 3; ++i) {
            tempDestRect.x = i * 2048;
            SDL_RenderCopy(renderer,sourceTexture,&tempsrcRect,&tempDestRect);
        }
        this->srcRect.h = 5632;
        this->srcRect.w = 1500;
        this->posRect.h = 5632;
        this->posRect.w = 1500;
    }

    SDLBackground1::~SDLBackground1() {
        SDL_DestroyTexture(sourceTexture);
        SDL_DestroyTexture(totalTexture);
    }

    void SDLBackground1::draw(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer, totalTexture, &srcRect, &posRect);
    }

}

