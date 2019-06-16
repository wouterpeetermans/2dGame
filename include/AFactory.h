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
        virtual std::shared_ptr<GameSpace::GameObject> CreatePlayer(int beginSpeed) =0;
        virtual std::shared_ptr<DrawEngine> GetDrawEngine()=0;
        virtual std::shared_ptr<GameObject> CreateRoad(std::shared_ptr<GameObject> player)=0;
        virtual std::shared_ptr<GameObject> CreateMiniVan(int xPos, int yPos, int speed)=0;
        virtual ~AFactory()= default;
    };
}




#endif //INC_2DGAME_AFACTORY_H
