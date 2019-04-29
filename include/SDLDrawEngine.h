//
// Created by wouter on 3/11/19.
//

#ifndef INC_2DGAME_SDLDRAWENGINE_H
#define INC_2DGAME_SDLDRAWENGINE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "IGameLoopController.h"
#include "Game.h"

#define window_Height 576 //!<set the height of the window
#define window_Width 1024 //!<set the width of the window

namespace SDLSpace {
class SDLDrawEngine : public GameSpace::IGameLoopController {
    public:
        SDLDrawEngine();
        ~SDLDrawEngine();

    void Run() override;

    void Init(std::shared_ptr<GameSpace::Game> game);

private:
        SDL_Window* window; //!< this wil be the pointer to the SDL window we are using
        SDL_Renderer* screenRenderer; //!< pointer to the renderer of window
        std::shared_ptr<GameSpace::Game> game;
    };
}


#endif //INC_2DGAME_SDLDRAWENGINE_H
