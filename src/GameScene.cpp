//
// Created by wouter on 6/16/19.
//

#include <cstdlib>
#include "GameScene.h"

namespace GameSpace {

    int GameScene::Update(int timeTook) {
        for (int i = 0; i < 3; ++i) {
            if(laneTimers[i] > laneTimerTresholds[i]){
                laneTimers[i] = 0;
                laneTimerTresholds[i] = rand()%1000;
                randomCarSpawner(-1875 + (i* 1875));
            }
        }
        for(std::shared_ptr<GameObject> object : *objectList){
            object->Update(timeTook);
        }
        return 0;
    }

    GameScene::GameScene(std::shared_ptr<AFactory> factory) {
        this->objectList = std::make_shared<std::list<std::shared_ptr<GameObject>>>();
        this->factory = factory;
        this->playerObject = factory->CreatePlayer(7);
        objectList->push_back(factory->CreateRoad(playerObject));
        objectList->push_back(playerObject);
        for(int& i : laneTimers){
            i = 0;
        }
        for(int& i : laneTimerTresholds){
            i = rand()%1000;
        }
    }

    void GameScene::randomCarSpawner(int xPos) {
        objectList->push_back(factory->CreateMiniVan(xPos,playerObject->getYpos()+10240,5));
    }


}