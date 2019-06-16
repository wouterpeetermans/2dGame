//
// Created by wouter on 3/25/19.
//



#include "SdlPlayer.h"

namespace SDLSpace {

    SdlPlayer::SdlPlayer(
            std::shared_ptr<SdlDrawEngine> drawEngine,
            int beginSpeed)
            : GameSpace::Player(beginSpeed){
        this->drawEngine = drawEngine;
        this->carSheet = drawEngine->LoadTexture("sprites/cars/Car.png");
        this->srcRect.x = 0;
        this->srcRect.y = 0;
        this->srcRect.h = 256;
        this->srcRect.w = 256;
        this->posRect.h = 512;
        this->posRect.w = 512;

        this->Ypos = 0; //todo remove
        this->Xpos = 0;
    }

    void SdlPlayer::Update(int timeTook) {
        //Ypos += 50;//todo remove
        Player::Update(timeTook);
        draw(drawEngine->getRenderer());
    }

    void SdlPlayer::draw(SDL_Renderer* renderer) {
        SDL_Point location = drawEngine->convertGameToScreenCoordinates(this->Xpos,this->Ypos);
        this->posRect.x = location.x - (posRect.w/2);
        this->posRect.y = 5900 - (posRect.h/2);
        SDL_RenderCopy(renderer, carSheet, &srcRect, &posRect);
    }

    SdlPlayer::~SdlPlayer() {
        SDL_DestroyTexture(carSheet);
    }


}