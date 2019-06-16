//
// Created by wouter on 3/11/19.
//

#ifndef INC_2DGAME_SDLFACTORY_H
#define INC_2DGAME_SDLFACTORY_H

#include "AFactory.h"
#include "SDLDrawEngine.h"

namespace SDLSpace {
    class SDLFactory : public GameSpace::AFactory {

    public:
        SDLFactory();
        ~SDLFactory() override;
        std::shared_ptr<GameSpace::GameObject> CreateCar(int Xpos, int Ypos) override;

        std::shared_ptr<GameSpace::DrawEngine> GetDrawEngine() override;

        std::shared_ptr<GameSpace::GameObject> CreateBackground1(std::shared_ptr<GameSpace::GameObject> player) override;

    private:
        std::shared_ptr<SDLDrawEngine> drawEngine;
    };
}


#endif //INC_2DGAME_SDLFACTORY_H
