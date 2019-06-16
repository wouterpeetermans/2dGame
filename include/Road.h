//
// Created by wouter on 6/15/19.
//

#ifndef INC_2DGAME_BACKGROUND_H
#define INC_2DGAME_BACKGROUND_H


#include "Player.h"
#include "StaticObject.h"

namespace GameSpace{
    class Road : public StaticObject  {
    public:
        explicit Road(std::shared_ptr<GameObject> player);

        void Update(int timeTook) override;

    protected:
        std::shared_ptr<GameObject> player;
    };
}



#endif //INC_2DGAME_BACKGROUND_H
