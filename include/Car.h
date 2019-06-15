//
// Created by wouter on 3/4/19.
//

#ifndef INC_2DGAME_CAR_H
#define INC_2DGAME_CAR_H


#include "GameObject.h"

namespace GameSpace{
    class Car: public GameObject {
    public:
        Car(int Xpos, int Ypos);
        virtual ~Car() override;

        virtual void Update() override;
    };
}



#endif //INC_2DGAME_CAR_H
