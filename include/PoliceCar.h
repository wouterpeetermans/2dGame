//
// Created by wouter on 6/17/19.
//

#ifndef INC_2DGAME_POLICECAR_H
#define INC_2DGAME_POLICECAR_H

#include "MovingObject.h"
#include "AFactory.h"

namespace GameSpace {
    class PoliceCar : public MovingObject {
    public:
        PoliceCar(int xPos, int yPos, int speed, std::shared_ptr<std::list<std::shared_ptr<GameObject>>> objectList,
                          std::shared_ptr<AFactory> factory);

        void Update(int timeTook) override;

    private:
        std::shared_ptr<std::list<std::shared_ptr<GameObject>>> objectList;
        std::shared_ptr<AFactory> factory;
        int nextDropPoint;
    };
}


#endif //INC_2DGAME_POLICECAR_H
