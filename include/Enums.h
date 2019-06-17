//
// Created by wouter on 3/11/19.
//

#ifndef INC_2DGAME_ENUMS_H
#define INC_2DGAME_ENUMS_H


namespace GameSpace {

    //! CollisionEnum
    /*! This Enum holds the types of collisions the player can encounter */
    enum CollisionEnum {
        POWER_UP,
        DAMAGE,
        CRASH,
        SOLID,
        EVENT,
        NONE
    };
}

#endif //INC_2DGAME_ENUMS_H
