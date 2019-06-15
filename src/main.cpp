

#include "AFactory.h"
#include "SDLFactory.h"
#include "Game.h"
#include <memory>

int main(){
    auto factory = std::make_shared<SDLSpace::SDLFactory>();
    auto game = GameSpace::Game(factory);
    game.Init();
    game.Run();
    game.Quit();
}

