//
// Created by wouter on 6/15/19.
//

#ifndef INC_2DGAME_PLAYER_H
#define INC_2DGAME_PLAYER_H


#include "MovingObject.h"

namespace GameSpace{
    class Player : public MovingObject {
    public:
        Player(int beginSpeed);
        void Update(int timeTook) override;

        void DetectCollisions(std::shared_ptr<std::list<std::shared_ptr<GameObject>>> coliderList) override;

    private:
        int health;
    };
}




#endif //INC_2DGAME_PLAYER_H
