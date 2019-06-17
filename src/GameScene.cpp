//
// Created by wouter on 6/16/19.
//

#include <cstdlib>
#include "GameScene.h"

namespace GameSpace {

    int GameScene::Update(int timeTook) {
        for (int i = 0; i < 3; ++i) {

            if(playerObject->getyPos() > laneTimerTresholds[i]){
                laneTimerTresholds[i] = playerObject->getyPos() + rand()%80000+3000;
                randomCarSpawner(-2500 + (i * 2500));
            }
        }
        for(std::shared_ptr<GameObject> object : *objectList){
            object->Update(timeTook);
        }
        playerObject->DetectCollisions(objectList);
        if(playerObject->isDestroyed())
            return playerObject->getyPos();
        return 0;//todo clean up objects that are no longer on screen.
    }

    GameScene::GameScene(std::shared_ptr<AFactory> factory) {
        this->objectList = std::make_shared<std::list<std::shared_ptr<GameObject>>>();
        this->factory = factory;
        this->playerObject = factory->CreatePlayer(10);
        objectList->push_back(factory->CreateRoad(playerObject));
        objectList->push_back(playerObject);
        for(int& i : laneTimers){
            i = 0;
        }
        for(int& i : laneTimerTresholds){
            i = rand()%10000;
        }
    }

    void GameScene::randomCarSpawner(int xPos) {
        int selector = rand()%100;
        if(selector > 70){
            objectList->push_back(factory->CreateMiniVan(xPos, playerObject->getyPos()+30720,4));
        } else {
            objectList->push_back(factory->CreatePoliceCar(xPos, playerObject->getyPos()+30720,4,objectList));
        }

    }


}