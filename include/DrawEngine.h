//
// Created by wouter on 3/25/19.
//

#ifndef INC_2DGAME_GAMELOOPCONTROLLER_H
#define INC_2DGAME_GAMELOOPCONTROLLER_H

//#include "Game.h"
#include "InputEvent.h"
#include <queue>

namespace GameSpace {
    //! Interface DrawEngine
    /*!
     * This is the interface to the Drawing system it contains functions necessary to communicate with the rendering
     * system.
     */
    class DrawEngine {
    public:
        //! Init function taking a game argument
        /*!
         * initialization function that loads all the things necessary
         */
        virtual void Init()=0;
        //! Update function shows all drawn objects to screen
        /*!
         * This function should draw all GameObjects that called their draw functions since this function was last ran.
         * It will then proceed to set everything up so that a new set of objects can be drawn.
         * It will block if needed to cap the framerate.
         * It will return a non zero status in the case that the program should end.
         */
        virtual int Update()=0;

        //! Destructor
        /*!
        * virtual destructor ensures complete destruction
        */
        virtual ~DrawEngine()= default;
    };
}



#endif //INC_2DGAME_GAMELOOPCONTROLLER_H