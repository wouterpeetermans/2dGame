//
// Created by wouter on 6/17/19.
//

#include <include/SdlBomb.h>

#include "SdlBomb.h"


namespace SDLSpace {

    SdlBomb::SdlBomb(std::shared_ptr<SdlDrawEngine> drawEngine, int Xpos, int Ypos) : Bomb(Xpos, Ypos) {
        this->drawEngine = drawEngine;
        this->destinationRect.h = 740;
        this->destinationRect.w = 740;
        this->destinationRect.x = 0;
        this->destinationRect.y = 0;
        this->bombTexture = this->drawEngine->LoadTexture("sprites/cars/Mini_van.png");
    }

    void SdlBomb::Update(int timeTook) {
        StaticObject::Update(timeTook);
        SDL_Point location = drawEngine->convertGameToScreenCoordinates(xPos,yPos);
        destinationRect.x = location.x - (destinationRect.w/2);
        destinationRect.y = location.y - (destinationRect.h/2);
        draw(drawEngine->getRenderer());
    }

    SdlBomb::~SdlBomb() {
        SDL_DestroyTexture(bombTexture);
    }

    void SdlBomb::draw(SDL_Renderer* renderer) {

    }
}