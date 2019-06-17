//
// Created by wouter on 6/17/19.
//

#ifndef INC_2DGAME_POLICECAR_H
#define INC_2DGAME_POLICECAR_H

#include "MovingObject.h"

namespace GameSpace {
    class PoliceCar : public MovingObject {
    public:
        PoliceCar(int xPos, int yPos, int speed);

        void Update(int timeTook) override;
    };
}


#endif //INC_2DGAME_POLICECAR_H
