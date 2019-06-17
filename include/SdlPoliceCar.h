//
// Created by wouter on 6/17/19.
//

#ifndef INC_2DGAME_SDLPOLICECAR_H
#define INC_2DGAME_SDLPOLICECAR_H


#include "PoliceCar.h"
#include "SdlDrawEngine.h"

namespace SDLSpace {
    class SdlPoliceCar : public GameSpace::PoliceCar {
    public:
        SdlPoliceCar(std::shared_ptr<SdlDrawEngine> drawEngine,
                int xPos,
                int yPos,
                int speed,
                std::shared_ptr<std::list<std::shared_ptr<GameObject>>> objectList);
        void Update(int timeTook) override;

    private:
        std::shared_ptr<std::list<std::shared_ptr<GameObject>>> objectList;
        void draw(SDL_Renderer* renderer);
        std::shared_ptr<SdlDrawEngine> drawEngine;
        SDL_Rect destinationRect;
        SDL_Texture* vanTexture;
    };
}


#endif //INC_2DGAME_SDLPOLICECAR_H
