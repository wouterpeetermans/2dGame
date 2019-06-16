//
// Created by wouter on 3/11/19.
//


#include <iostream>
#include <include/SdlDrawEngine.h>

#include "SdlDrawEngine.h"

namespace SDLSpace {


    SdlDrawEngine::SdlDrawEngine() {
        SDL_Init(SDL_INIT_EVERYTHING); // everything because why not
        window = SDL_CreateWindow("sdlGame", // give the window a name
                                  SDL_WINDOWPOS_UNDEFINED, // put it where you want
                                  SDL_WINDOWPOS_UNDEFINED,
                                  window_Width, //window width defined in the header file
                                  window_Height, //same here
                                  SDL_WINDOW_RESIZABLE);// I like resizable windows so why not
        if (window == nullptr) {
            std::cout << "window could not be created" << SDL_GetError() << std::endl;
        } else {
            screenRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (screenRenderer == nullptr) {
                std::cout << "screen render could not be created" << SDL_GetError() << std::endl;
            } else {
                if (0 != SDL_SetRenderDrawColor(screenRenderer, 43, 165, 98, 255)) {
                    std::cout << "something wrong with renderDrawColor" << SDL_GetError() << std::endl;
                }
                if (!IMG_Init(IMG_INIT_PNG)) {
                    std::cout << "image library could not be loaded" << IMG_GetError() << std::endl;
                }
            }
        }
        eventObservers = std::make_shared<std::list<ISdlEventListener*>>();
        defaultRenderTexture = CreateTexture(1500,6144);
        SDL_SetRenderTarget(screenRenderer,defaultRenderTexture);
    }

    SdlDrawEngine::~SdlDrawEngine() {
        SDL_DestroyTexture(defaultRenderTexture);
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(screenRenderer);
        SDL_Quit();
        IMG_Quit();
    }

    void SdlDrawEngine::Init() {
        //future proofing
        SDL_RenderClear(screenRenderer);
    }

    SDL_Texture* SdlDrawEngine::LoadTexture(std::string path) {
        SDL_Texture* newTexture = NULL; //here I store the newly generated surface
        SDL_Surface* loadedSurface = IMG_Load(path.c_str());//load a surface from a file
        if (loadedSurface == NULL) {//detect if there is something in is and if not give some error
            std::cout << "image could not be loaded" << SDL_GetError() << std::endl;
        } else {//optimize the surface for the screen we are using
            newTexture = SDL_CreateTextureFromSurface(screenRenderer, loadedSurface);
            if (newTexture == NULL) {//same as above
                std::cout << "texture not created " << SDL_GetError() << std::endl;
            }
            SDL_FreeSurface(loadedSurface);//prevent memory leaks because they are anoying
        }
        return newTexture; //return something
    }

    SDL_Texture* SdlDrawEngine::CreateTexture(int width, int height) {
        SDL_Texture* newTexture = SDL_CreateTexture(screenRenderer, SDL_GetWindowPixelFormat(window),
                                                    SDL_TEXTUREACCESS_TARGET, width, height);
        if (newTexture == NULL) {
            std::cout << "creating a texture failed" << '\n';
        }
        return newTexture;
    }

    int SdlDrawEngine::Update() {
//        bool quit = false; //this bool tels if the user has quited the hard game already
        SDL_Event e;// a place to store an event of some type
//
//        while (!quit){
//            unsigned int startTime=0 , currentTime=0 , timeTook=0;
//
//            startTime = SDL_GetTicks();//get wath time we started to cap the framerate
//
//            std::shared_ptr<std::queue<std::shared_ptr<GameSpace::InputEvent>>> eventQueue(new std::queue<std::shared_ptr<GameSpace::InputEvent>>());
        while (SDL_PollEvent(&e) != 0) {//a loop to go over all the events the user managed to create in a fraction of a second
            if (e.type == SDL_QUIT) { //now I am able to use the litle cross on top of the window
                return 1;
            }
            for(ISdlEventListener* l : *eventObservers){
                l->onEvent(&e);
            }
//                //held.GetKeys(&e);//todo: implement the filling of the queue fully with events from sdl.
//                eventQueue->push(std::shared_ptr<GameSpace::InputEvent>(new GameSpace::InputEvent(GameSpace::Backward,GameSpace::Pressed)));
        }


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
        SDL_GetWindowSize(this->window,&windowWith,&windowHeight);
        trackRect.h = windowHeight;
        trackRect.w = trackRect.h * 375 / 512;
        if((windowWith-minimapRect.w)<trackRect.w)
            trackRect.w = windowWith-125;
        trackRect.x = minimapRect.w;
        trackRect.y = 0;

        SDL_SetRenderTarget(screenRenderer,NULL);
        SDL_RenderCopy(screenRenderer, defaultRenderTexture, &vieuwPortRect, &trackRect);
        SDL_RenderCopy(screenRenderer,defaultRenderTexture, NULL, &minimapRect);

        SDL_RenderPresent(screenRenderer);
        SDL_RenderClear(screenRenderer);
        resetRendererTexture();
        SDL_RenderClear(screenRenderer);
        return 0;
    }

    SDL_Renderer* SdlDrawEngine::getRenderer() {
        return screenRenderer;
    }

    SDL_Point SdlDrawEngine::convertGameToScreenCoordinates(int xPos, int yPos) {
        SDL_Point point;
        point.y = 6144 - (yPos / 5);
        point.x = 750 + (xPos / 5);

        return point;
    }

    void SdlDrawEngine::resetRendererTexture() {
        SDL_SetRenderTarget(screenRenderer,defaultRenderTexture);
    }

    int SdlDrawEngine::getTimeMs() {
        return SDL_GetTicks();
    }

    void SdlDrawEngine::subscribeToEvents(ISdlEventListener* listener) {
        eventObservers->push_back(listener);
    }

    void SdlDrawEngine::unSubscribeFromEvents(ISdlEventListener* listener) {
        eventObservers->remove(listener);
    }
}

