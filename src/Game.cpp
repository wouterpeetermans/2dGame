//
// Created by wouter on 3/4/19.
//
#include "MiniVan.h"

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
        auto gameScene = factory->CreateGameScene(factory);
        bool isQuit = false;
        int startTime, stopTime, timeTook;
        startTime = stopTime = 0;
        while (!isQuit) {
            timeTook = stopTime - startTime;
            startTime = drawEngine->getTimeMs();
            gameScene->Update(timeTook);
            if(drawEngine->Update())
                isQuit = true;
            stopTime = drawEngine->getTimeMs();
        }
    }

    void Game::Quit() {

    }

    Game::~Game() {

    }


}

