//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_STATICOBJECT_H
#define INC_2DGAME_STATICOBJECT_H


#include "GameObject.h"

namespace GameSpace{
    class StaticObject : public GameObject {
    public:
        StaticObject(int Xpos, int Ypos);

        void Update(int timeTook) override;
    };
}



#endif //INC_2DGAME_STATICOBJECT_H
