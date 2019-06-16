//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_MOVINGOBJECT_H
#define INC_2DGAME_MOVINGOBJECT_H

#include "GameObject.h"

namespace GameSpace{
    class MovingObject : public GameObject {
    public:
        void Update(int timeTook) override;


    };
}



#endif //INC_2DGAME_MOVINGOBJECT_H
