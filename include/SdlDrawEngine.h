//
// Created by wouter on 3/11/19.
//

#ifndef INC_2DGAME_SDLDRAWENGINE_H
#define INC_2DGAME_SDLDRAWENGINE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "DrawEngine.h"
#include <string>

#define window_Height 576 //!<set the height of the window
#define window_Width 1024 //!<set the width of the window

namespace SDLSpace {
    class SdlDrawEngine : public GameSpace::DrawEngine {
    public:
        SdlDrawEngine();

        ~SdlDrawEngine() override;

        int Update() override;

        void Init() override;

        SDL_Texture* LoadTexture(std::string path);

        SDL_Renderer* getRenderer();

        void resetRendererTexture();

        SDL_Texture* CreateTexture(int width, int height);

        SDL_Point convertGameToScreenCoordinates(int xPos, int yPos);

        int getTimeMs();

    private:
        SDL_Window* window; //!< this wil be the pointer to the SDL window we are using
        SDL_Renderer* screenRenderer; //!< pointer to the renderer of window
        SDL_Texture* defaultRenderTexture;

    };
}


#endif //INC_2DGAME_SDLDRAWENGINE_H
