//
// Created by wouter on 6/16/19.
//

#include <include/SdlGameScene.h>

#include "SdlGameScene.h"

namespace SDLSpace{
    SdlGameScene::SdlGameScene(std::shared_ptr<SdlDrawEngine> drawEngine, std::shared_ptr<GameSpace::AFactory> factory)
    : GameScene(factory) {
        this->drawEngine = drawEngine;
        this->renderer = drawEngine->getRenderer();
        this->gameSceneRenderTexture = drawEngine->CreateTexture(1500, 6144);
    }

    void SdlGameScene::draw(SDL_Renderer* renderer) {
        SDL_Rect vieuwPortRect, minimapRect, trackRect;
        vieuwPortRect.h = 2048;
        vieuwPortRect.w = 1500;
        vieuwPortRect.x = 0;
        vieuwPortRect.y = 4096;
        minimapRect.h = 512;
        minimapRect.w = 125;
        minimapRect.x = 0;
        minimapRect.y = 0;
        int windowWith, windowHeight;
        SDL_GetWindowSize(this->drawEngine->getWindow(), &windowWith, &windowHeight);
        trackRect.h = windowHeight;
        trackRect.w = trackRect.h * 375 / 512;
        if ((windowWith - minimapRect.w) < trackRect.w)
            trackRect.w = windowWith - 125;
        trackRect.x = minimapRect.w;
        trackRect.y = 0;

        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderCopy(renderer, gameSceneRenderTexture, &vieuwPortRect, &trackRect);
        SDL_RenderCopy(renderer, gameSceneRenderTexture, NULL, &minimapRect);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_SetRenderTarget(renderer,gameSceneRenderTexture);
        SDL_RenderClear(renderer);
    }

    int SdlGameScene::Update(int timeTook) {
        SDL_SetRenderTarget(renderer,gameSceneRenderTexture);
        SDL_RenderClear(renderer);
        int returnValue = GameScene::Update(timeTook);
        draw(renderer);
        return returnValue;
    }

    SdlGameScene::~SdlGameScene() {
        SDL_DestroyTexture(gameSceneRenderTexture);
    }

}

