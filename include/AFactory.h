//
// Created by wouter on 3/4/19.
//

#ifndef INC_2DGAME_AFACTORY_H
#define INC_2DGAME_AFACTORY_H

#include "GameObject.h"
#include "DrawEngine.h"
#include <memory>


namespace GameSpace {
    class AFactory {
    public:
        virtual std::shared_ptr<GameObject> CreateCar(int Xpos, int Ypos)=0;
        virtual std::shared_ptr<DrawEngine> GetDrawEngine()=0;
        virtual ~AFactory()= default;
    };
}




#endif //INC_2DGAME_AFACTORY_H
