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
        explicit SDLCar(std::shared_ptr<SDLDrawEngine>);
        void Draw() override;
        ~SDLCar() override;

    private:
        std::shared_ptr<SDLDrawEngine> drawEngine;
    };

}




#endif //INC_2DGAME_SDLCAR_H
