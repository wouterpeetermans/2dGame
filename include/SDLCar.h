//
// Created by wouter on 3/25/19.
//

#ifndef INC_2DGAME_SDLCAR_H
#define INC_2DGAME_SDLCAR_H

#include "SDLDrawEngine.h"
#include "Car.h"

namespace SDLSpace{

class SDLCar : public GameSpace::Car {
    public:
        explicit SDLCar(std::shared_ptr<SDLDrawEngine>, int Xpos, int Ypos);
        void Update(int timeTook) override;
        ~SDLCar() override;

    bool HasCollision(std::shared_ptr<GameObject> object) override;

    void DetectCollisions(std::shared_ptr<std::list<std::shared_ptr<GameObject>>> ColliderList) override;


private:
        std::shared_ptr<SDLDrawEngine> drawEngine;
        SDL_Texture* carSheet;
        SDL_Rect posRect;
        SDL_Rect srcRect;
        void draw(SDL_Renderer* renderer);
    };

}




#endif //INC_2DGAME_SDLCAR_H
