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
        virtual ~SDLFactory() override;
        std::shared_ptr<GameSpace::GameObject> CreateCar() override;

        //std::shared_ptr<GameSpace::IGameLoopController> CreateGameLoop() override;

    private:
        std::shared_ptr<SDLDrawEngine> drawEngine;
    };
}


#endif //INC_2DGAME_SDLFACTORY_H
