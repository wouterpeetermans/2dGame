//
// Created by wouter on 3/4/19.
//

#ifndef INC_2DGAME_GAME_H
#define INC_2DGAME_GAME_H


#include <queue>
#include "AFactory.h"
#include "DrawEngine.h"


namespace GameSpace{
    //! Game class
    /*!
     * This class controls the main flow of the game. The state engine will be in this class.
     * In the constructor it is passed a factory to create all the objects needed.
     */
    class Game {
    public:
        explicit Game(std::shared_ptr<AFactory> factory);
        void initialize();
        void Run();
        void Quit();
        ~Game();


    private:
        std::shared_ptr<AFactory> factory;
        std::shared_ptr<DrawEngine> drawEngine;



    };

}



#endif //INC_2DGAME_GAME_H
