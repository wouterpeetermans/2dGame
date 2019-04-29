//
// Created by wouter on 3/4/19.
//

#ifndef INC_2DGAME_AFACTORY_H
#define INC_2DGAME_AFACTORY_H

#include "GameObject.h"
//#include "IGameLoopController.h"
#include <memory>


namespace GameSpace {
    class AFactory {
    public:
        virtual std::shared_ptr<GameObject> CreateCar()=0;
        //virtual std::shared_ptr<IGameLoopController> CreateGameLoop()=0;
        virtual ~AFactory()= default;
    };
}




#endif //INC_2DGAME_AFACTORY_H
