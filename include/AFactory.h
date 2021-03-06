//
// Created by wouter on 3/4/19.
//

#ifndef INC_2DGAME_AFACTORY_H
#define INC_2DGAME_AFACTORY_H

#include "GameObject.h"
#include "DrawEngine.h"
#include "Scene.h"
#include "Player.h"
#include <memory>


namespace GameSpace {
    class AFactory {
    public:
        virtual std::shared_ptr<GameSpace::Player> CreatePlayer(int beginSpeed) =0;
        virtual std::shared_ptr<DrawEngine> GetDrawEngine()=0;
        virtual std::shared_ptr<GameObject> CreateRoad(std::shared_ptr<GameObject> player)=0;
        virtual std::shared_ptr<GameObject> CreateMiniVan(int xPos, int yPos, int speed)=0;
        virtual std::shared_ptr<Scene> CreateGameScene(std::shared_ptr<AFactory> factory) =0;
        virtual std::shared_ptr<GameObject> CreatePoliceCar(
                int xPos,
                int yPos,
                int speed,
                std::shared_ptr<std::list<std::shared_ptr<GameObject>>> objectList,
                std::shared_ptr<AFactory> factory)=0;
        virtual std::shared_ptr<GameObject> CreateBomb(int xPos, int yPos)=0;
        virtual ~AFactory()= default;
    };
}




#endif //INC_2DGAME_AFACTORY_H
