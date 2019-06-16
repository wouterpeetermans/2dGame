//
// Created by wouter on 6/15/19.
//

#ifndef INC_2DGAME_BACKGROUND_H
#define INC_2DGAME_BACKGROUND_H


#include "Player.h"

namespace GameSpace{
    class Background1 : public GameObject {
    public:
        explicit Background1(std::shared_ptr<GameObject> player);

        void Update(int timeTook) override;

    protected:
        std::shared_ptr<GameObject> player;
    };
}



#endif //INC_2DGAME_BACKGROUND_H
