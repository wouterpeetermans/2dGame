//
// Created by wouter on 6/16/19.
//

#include <include/SdlMinivan.h>

#include "SdlMinivan.h"

namespace SDLSpace{
    void SdlMinivan::Update(int timeTook) {
        MiniVan::Update(timeTook);
        SDL_Point location = drawEngine->convertGameToScreenCoordinates(Xpos,Ypos);
        destinationRect.x = location.x - (destinationRect.w/2);
        destinationRect.y = location.y - (destinationRect.h/2);
        draw(drawEngine->getRenderer());
    }

    void SdlMinivan::draw(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer,vanTexture,NULL,&destinationRect);
    }

    SdlMinivan::SdlMinivan(std::shared_ptr<SdlDrawEngine> drawEngine, int xPos, int yPos, int speed)
    : MiniVan(xPos, yPos, speed) {
        this->drawEngine = drawEngine;
        this->destinationRect.h = 512;
        this->destinationRect.w = 512;
        this->destinationRect.x = 0;
        this->destinationRect.y = 0;
        this->vanTexture = this->drawEngine->LoadTexture("sprites/cars/Mini_van.png");
    }

    SdlMinivan::~SdlMinivan() {

    }
}


