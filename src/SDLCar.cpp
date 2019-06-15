//
// Created by wouter on 3/25/19.
//



#include "SDLCar.h"

namespace SDLSpace {

    SDLCar::SDLCar(std::shared_ptr<SDLDrawEngine> drawEngine, int Xpos, int Ypos) : Car(Xpos,Ypos) {
        this->drawEngine = drawEngine;
        this->carSheet = drawEngine->LoadTexture("sprites/cars/Car.png");
        this->posRect.x = Xpos;
        this->posRect.y = Ypos;
        this->posRect.h = 256;
        this->posRect.w = 256;
        this->srcRect.x = 0;
        this->srcRect.y = 0;
        this->srcRect.h = 256;
        this->srcRect.w = 256;
    }

    void SDLCar::Update(){
        draw(drawEngine->getRenderer());
    }

    void SDLCar::draw(SDL_Renderer * renderer) {
        SDL_RenderCopy(renderer,carSheet, &srcRect, &posRect);
    }

    SDLCar::~SDLCar() {
        SDL_DestroyTexture(carSheet);
    }


}