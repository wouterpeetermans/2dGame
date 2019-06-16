//
// Created by wouter on 3/25/19.
//

#ifndef INC_2DGAME_SDLCAR_H
#define INC_2DGAME_SDLCAR_H

#include "SdlDrawEngine.h"
#include "Player.h"

namespace SDLSpace{

class SdlPlayer : public GameSpace::Player {
    public:
        explicit SdlPlayer(std::shared_ptr<SdlDrawEngine>, int beginSpeed);
        void Update(int timeTook) override;
        ~SdlPlayer() override;



private:
        std::shared_ptr<SdlDrawEngine> drawEngine;
        SDL_Texture* carSheet;
        SDL_Rect posRect;
        SDL_Rect srcRect;
        void draw(SDL_Renderer* renderer);
    };

}




#endif //INC_2DGAME_SDLCAR_H
