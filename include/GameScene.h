//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_GAMESCENE_H
#define INC_2DGAME_GAMESCENE_H

#include "Scene.h"
#include "GameObject.h"
#include "AFactory.h"
#include <memory>
#include <list>

namespace GameSpace {
    class GameScene : public Scene {
    public:
        GameScene(std::shared_ptr<AFactory> factory);
        int Update(int timeTook) override;

    protected:
        std::shared_ptr<std::list<std::shared_ptr<GameObject>>> objectList;
        std::shared_ptr<AFactory> factory;
        std::shared_ptr<GameObject> playerObject;
    private:
        void randomCarSpawner(int xPos);
        int laneTimers[3];
        int laneTimerTresholds[3];
    };
}



#endif //INC_2DGAME_GAMESCENE_H
