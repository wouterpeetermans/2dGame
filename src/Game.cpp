//
// Created by wouter on 3/4/19.
//

#include <include/Game.h>

#include "Game.h"

namespace GameSpace {
    Game::Game(std::unique_ptr<AFactory> factory) {
        this->factory = std::move(factory);
    }

    void Game::Update(std::shared_ptr<std::queue<std::shared_ptr<GameSpace::InputEvent>>> eventQueue,
                      unsigned int timePassed) {

    }

    void Game::Init() {

    }

    void Game::Run() {

    }

    void Game::Draw() {

    }

}

