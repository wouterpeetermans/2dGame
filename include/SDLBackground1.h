//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_SDLBACKGROUND1_H
#define INC_2DGAME_SDLBACKGROUND1_H


#include "SDLDrawEngine.h"
#include "Background1.h"

namespace SDLSpace{
class SDLBackground1 : public GameSpace::Background1 {
public:
    SDLBackground1(std::shared_ptr<GameObject> player, std::shared_ptr<SDLDrawEngine> drawEngine);
    ~SDLBackground1() override;

    void DetectCollisions(std::shared_ptr<std::list<std::shared_ptr<GameObject>>> ColliderList) override;

    bool HasCollision(std::shared_ptr<GameObject> object) override;

    void Update(int TimeTook) override;

private:
    void draw(SDL_Renderer* renderer);
    std::shared_ptr<SDLDrawEngine> drawEngine;
    SDL_Texture* sourceTexture;
    SDL_Texture* totalTexture;
    SDL_Rect srcRect;
    SDL_Rect posRect;

};
}



#endif //INC_2DGAME_SDLBACKGROUND1_H
