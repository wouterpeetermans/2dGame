

#include "AFactory.h"
#include "SdlFactory.h"
#include "Game.h"
#include <memory>

int main(){
    auto factory = std::make_shared<SDLSpace::SdlFactory>();
    auto game = GameSpace::Game(factory);
    game.initialize();
    game.Run();
    game.Quit();
}

