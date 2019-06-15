//
// Created by wouter on 3/4/19.
//
#include "Car.h"

#include "Game.h"

namespace GameSpace {
    Game::Game(std::shared_ptr<AFactory> factory) {
        this->factory = factory;
    }


    void Game::Init() {
        this->drawEngine = factory->GetDrawEngine();
        drawEngine->Init();
    }

    void Game::Run() {
        bool quit = false;
        std::shared_ptr<GameObject> testcar = factory->CreateCar(0,0);
        while (!drawEngine->Update()){
            testcar->Update(0);
        }
    }

    void Game::Quit() {

    }

    Game::~Game() {

    }


}

