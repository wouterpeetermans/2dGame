//
// Created by wouter on 3/11/19.
//

#ifndef INC_2DGAME_SDLDRAWENGINE_H
#define INC_2DGAME_SDLDRAWENGINE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "DrawEngine.h"
#include "Game.h"

#define window_Height 576 //!<set the height of the window
#define window_Width 1024 //!<set the width of the window

namespace SDLSpace {
class SDLDrawEngine : public GameSpace::DrawEngine {
    public:
        SDLDrawEngine();
        ~SDLDrawEngine() override;

    int Update() override;

    void Init() override;
    SDL_Texture* LoadTexture(std::string path);
    SDL_Renderer* getRenderer();

private:
        SDL_Window* window; //!< this wil be the pointer to the SDL window we are using
        SDL_Renderer* screenRenderer; //!< pointer to the renderer of window
        std::shared_ptr<GameSpace::Game> game;
    };
}


#endif //INC_2DGAME_SDLDRAWENGINE_H
