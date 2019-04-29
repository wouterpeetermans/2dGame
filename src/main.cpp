

#include "AFactory.h"
#include "SDLFactory.h"
#include "Game.h"
#include <memory>

int main(){
    auto factory = std::make_unique<SDLSpace::SDLFactory>(SDLSpace::SDLFactory());
    auto game = std::make_unique<GameSpace::Game>(GameSpace::Game(std::move(factory)));
}

