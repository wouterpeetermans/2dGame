//
// Created by wouter on 3/4/19.
//
#include "Car.h"

#include "Game.h"

namespace GameSpace {
    Game::Game(std::shared_ptr<AFactory> factory) {
        this->factory = factory;
        this->drawEngine = factory->GetDrawEngine();
        drawEngine->Init();
    }


    void Game::initialize() {

    }

    void Game::Run() {
        bool quit = false;
        std::shared_ptr<GameObject> testcar = factory->CreateCar(0, 0);
        std::shared_ptr<GameObject> backdrop = factory->CreateBackground1(testcar);
        while (!drawEngine->Update()) {
            backdrop->Update(0);
            testcar->Update(0);
        }
    }

    void Game::Quit() {

    }

    Game::~Game() {

    }


}

