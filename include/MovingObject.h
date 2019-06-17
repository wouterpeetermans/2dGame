//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_MOVINGOBJECT_H
#define INC_2DGAME_MOVINGOBJECT_H

#include "GameObject.h"
#include "SpeedVector.h"

namespace GameSpace{
    class MovingObject : public GameObject {
    public:
        MovingObject(int xPos, int yPos);
        MovingObject(int xPos, int yPos, std::shared_ptr<SpeedVector> speedVector);
        void Update(int timeTook) override;

        CollisionEnum Collides(const GameObject* object) override;

        std::shared_ptr<SpeedVector> speedVector;
    };
}



#endif //INC_2DGAME_MOVINGOBJECT_H
