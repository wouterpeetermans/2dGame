//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_ISDLEVENTLISTENER_H
#define INC_2DGAME_ISDLEVENTLISTENER_H

#include <SDL2/SDL.h>

namespace SDLSpace{
    class ISdlEventListener {
    public:
        virtual void onEvent(SDL_Event* e)=0;
    };
}



#endif //INC_2DGAME_ISDLEVENTLISTENER_H
