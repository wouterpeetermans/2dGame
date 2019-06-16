//
// Created by wouter on 3/25/19.
//



#include "SdlCar.h"

namespace SDLSpace {

    SdlCar::SdlCar(std::shared_ptr<SdlDrawEngine> drawEngine, int Xpos, int Ypos) : Car(Xpos, Ypos) {
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
        this->Ypos = 2000; //todo remove
    }

    void SdlCar::Update(int timeTook) {
        Ypos += 50;//todo remove
        Car::Update(timeTook);
        draw(drawEngine->getRenderer());
    }

    void SdlCar::draw(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer, carSheet, &srcRect, &posRect);
    }

    SdlCar::~SdlCar() {
        SDL_DestroyTexture(carSheet);
    }


}