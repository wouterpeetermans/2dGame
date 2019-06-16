//
// Created by wouter on 3/25/19.
//



#include "SdlPlayer.h"
#include "SpeedVector.h"

namespace SDLSpace {

    SdlPlayer::SdlPlayer(
            std::shared_ptr<SdlDrawEngine> drawEngine,
            int beginSpeed)
            : GameSpace::Player(beginSpeed){
        this->drawEngine = drawEngine;
        this->carSheet = drawEngine->LoadTexture("sprites/cars/Car.png");
        this->posRect.h = 512;
        this->posRect.w = 512;

        this->Ypos = 0;
        this->Xpos = 0;
        drawEngine->subscribeToEvents(this);
    }

    void SdlPlayer::Update(int timeTook) {
        Player::Update(timeTook);
        drawEngine->setZeroOfset((Ypos/5)-244);
        draw(drawEngine->getRenderer());
    }

    void SdlPlayer::draw(SDL_Renderer* renderer) {
        SDL_Point location = drawEngine->convertGameToScreenCoordinates(this->Xpos, this->Ypos);
        this->posRect.x = location.x - (posRect.w/2);
        this->posRect.y = 5900 - (posRect.h/2);
        SDL_RenderCopy(renderer, carSheet, NULL, &posRect);
    }

    SdlPlayer::~SdlPlayer() {
        drawEngine->unSubscribeFromEvents(this);
        SDL_DestroyTexture(carSheet);
    }

    void SdlPlayer::onEvent(SDL_Event* e) {
        GameSpace::SpeedVector leftVector(-3,0);
        GameSpace::SpeedVector rightVector(3,0);
        if(e->type == SDL_KEYDOWN) {//keys pressed
            switch (e->key.keysym.sym) {
                case SDLK_RIGHT:
                    //pos++;
                    speedVector->xZero();
                    *speedVector.get() += rightVector;
                    break;
                case SDLK_LEFT:
                    //pos--;
                    speedVector.get()->xZero();
                    *speedVector.get() += leftVector;
                    break;
                case SDLK_UP:
                    break;
                default:
                    //speedVector.xZero();
                    break;
            }
        } else if(e->type == SDL_KEYUP) {//keys pressed
            switch (e->key.keysym.sym) {
                case SDLK_RIGHT:
                    //pos++;
                    speedVector->xZero();
                    break;
                case SDLK_LEFT:
                    //pos--;
                    speedVector->xZero();
                    break;
                case SDLK_UP:
                    break;
                default:
                    //speedVector.xZero();
                    break;
            }
        }
    }


}