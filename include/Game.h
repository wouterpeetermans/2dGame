//
// Created by wouter on 3/4/19.
//

#ifndef INC_2DGAME_GAME_H
#define INC_2DGAME_GAME_H


#include <queue>
#include "AFactory.h"
#include "InputEvent.h"
#include "IGameLoopController.h"


namespace GameSpace{
    //! Game class
    /*!
     * This class controls the main flow of the game. The state engine will be in this class.
     * In the constructor it is passed a factory to create all the objects needed.
     */
    class Game {
    public:
        explicit Game(std::unique_ptr<AFactory> factory);
        void Init();
        void Run();
        void Update(std::shared_ptr<std::queue<std::shared_ptr<InputEvent>>> eventQueue, unsigned int timePassed);
        void Draw();


    private:
        std::unique_ptr<AFactory> factory;
        std::shared_ptr<IGameLoopController> gameLoopController;



    };

}



#endif //INC_2DGAME_GAME_H
