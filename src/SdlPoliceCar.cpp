//
// Created by wouter on 6/17/19.
//

#include <include/SdlPoliceCar.h>

#include "SdlPoliceCar.h"

namespace SDLSpace{
    void SDLSpace::SdlPoliceCar::Update(int timeTook) {
        PoliceCar::Update(timeTook);
        SDL_Point location = drawEngine->convertGameToScreenCoordinates(xPos,yPos);
        destinationRect.x = location.x - (destinationRect.w/2);
        destinationRect.y = location.y - (destinationRect.h/2);
        draw(drawEngine->getRenderer());
    }

    SDLSpace::SdlPoliceCar::SdlPoliceCar(
            std::shared_ptr<SDLSpace::SdlDrawEngine> drawEngine,
            int xPos,
            int yPos,
            int speed,
            std::shared_ptr<std::list<std::shared_ptr<GameSpace::GameObject>>> objectList,
            std::shared_ptr<GameSpace::AFactory> factory)
            : PoliceCar::PoliceCar(xPos, yPos, speed, objectList,
                                   factory) {
        this->drawEngine = drawEngine;
        this->destinationRect.h = 512;
        this->destinationRect.w = 512;
        this->destinationRect.x = 0;
        this->destinationRect.y = 0;
        this->vanTexture = this->drawEngine->LoadTexture("sprites/cars/Police.png");
    }

    void SdlPoliceCar::draw(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer,vanTexture,NULL,&destinationRect);
    }

    SdlPoliceCar::~SdlPoliceCar() {
        SDL_DestroyTexture(vanTexture);
    }
}


