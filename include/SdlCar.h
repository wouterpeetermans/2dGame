//
// Created by wouter on 3/25/19.
//

#ifndef INC_2DGAME_SDLCAR_H
#define INC_2DGAME_SDLCAR_H

#include "SdlDrawEngine.h"
#include "Car.h"

namespace SDLSpace{

class SdlCar : public GameSpace::Car {
    public:
        explicit SdlCar(std::shared_ptr<SdlDrawEngine>, int Xpos, int Ypos);
        void Update(int timeTook) override;
        ~SdlCar() override;



private:
        std::shared_ptr<SdlDrawEngine> drawEngine;
        SDL_Texture* carSheet;
        SDL_Rect posRect;
        SDL_Rect srcRect;
        void draw(SDL_Renderer* renderer);
    };

}




#endif //INC_2DGAME_SDLCAR_H
