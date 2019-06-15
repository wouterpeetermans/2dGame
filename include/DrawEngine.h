//
// Created by wouter on 3/25/19.
//

#ifndef INC_2DGAME_GAMELOOPCONTROLLER_H
#define INC_2DGAME_GAMELOOPCONTROLLER_H

//#include "Game.h"
#include "InputEvent.h"
#include <queue>

namespace GameSpace {
    //! Interface IGameLoopController
    /*!
     * This interface provides a way to control the game loop from outside the Game class. This is a necessity to let
     * for example SDL control the speed of the gameloop.
     */
    class IGameLoopController {
    public:
        //! Init function taking a game argument
        /*!
         * initialization function that loads all the things necessary to start up the gameloop
         * @param game this should be the game to which the gameloopcontroller has effect.
         */
        //virtual void Init(std::shared_ptr<Game> game)=0;//todo: instead of game pass function pointers because otherwise header files collide
        //! Run function exits when game is over
        /*!
         * This function is blocking and will keep running the game loop. See implementations for when it stops
         */
        virtual void Run()=0;
    };
}



#endif //INC_2DGAME_GAMELOOPCONTROLLER_H