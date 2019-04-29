//
// Created by wouter on 3/11/19.
//


#include <iostream>
#include "SDLDrawEngine.h"

namespace SDLSpace{


    SDLDrawEngine::SDLDrawEngine() {
        SDL_Init(SDL_INIT_EVERYTHING); // everything because why not
        window = SDL_CreateWindow("sdlGame", // give the window a name
                                  SDL_WINDOWPOS_UNDEFINED, // put it where you want
                                  SDL_WINDOWPOS_UNDEFINED,
                                  window_Width, //window width defined in the header file
                                  window_Height, //same here
                                  SDL_WINDOW_RESIZABLE);// I like resizable windows so why not
        if (window == nullptr) {
            std::cout<< "window could not be created" << SDL_GetError() << std::endl;
        }
        else {
            screenRenderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (screenRenderer == nullptr) {
                std::cout << "screen render could not be created" << SDL_GetError() << std::endl;
            }
            else {
                if(0!=SDL_SetRenderDrawColor(screenRenderer, 0x12, 0xFF, 0xFF, 0xFF)){
                    std::cout << "something wrong with renerDrawCollor" << SDL_GetError() << std::endl;
                }
                if(!IMG_Init(IMG_INIT_PNG)){
                    std::cout<<"image library could not be loaded" << IMG_GetError() <<std::endl;
                }
            }
        }
    }

    SDLDrawEngine::~SDLDrawEngine() {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(screenRenderer);
        SDL_Quit();
        IMG_Quit();
    }

    void SDLDrawEngine::Init(std::shared_ptr<GameSpace::Game> game) {
        this->game = game;
    }

    void SDLDrawEngine::Run() {
        bool quit = false; //this bool tels if the user has quited the hard game already
        SDL_Event e;// a place to store an event of some type

        while (!quit){
            unsigned int startTime=0 , currentTime=0 , timeTook=0;

            startTime = SDL_GetTicks();//get wath time we started to cap the framerate

            std::shared_ptr<std::queue<std::shared_ptr<GameSpace::InputEvent>>> eventQueue(new std::queue<std::shared_ptr<GameSpace::InputEvent>>());
            while ( SDL_PollEvent( &e ) !=0 ) {//a loop to go over all the events the user managed to create in a fraction of a second
                if (e.type == SDL_QUIT) { //now I am able to use the litle cross on top of the window
                    quit = true;
                }
                //held.GetKeys(&e);//todo: implement the filling of the queue fully with events from sdl.
                eventQueue->push(std::shared_ptr<GameSpace::InputEvent>(new GameSpace::InputEvent(GameSpace::Backward,GameSpace::Pressed)));
            }
            //held.Update(timeTook,l1.GetColidables(),l1.GetAmountColidables());
            game->Update(eventQueue,timeTook);
            SDL_RenderClear(screenRenderer);
            game->Draw();

            SDL_RenderPresent(screenRenderer);
            currentTime = SDL_GetTicks();
            if (currentTime<(startTime+16)) {//cap the framerate at about 100 fps not used when vsync is working
                SDL_Delay((startTime+16)-currentTime);
            }
            timeTook = SDL_GetTicks() - startTime;
        }

    }



}

