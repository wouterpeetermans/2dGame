//
// Created by wouter on 3/11/19.
//

#ifndef INC_2DGAME_ENUMS_H
#define INC_2DGAME_ENUMS_H


namespace GameSpace {

    //! InputEnum
    /*! This Enum holds possible inputs that can be coupled to input of choice */
    enum InputEnum{
        Forward,
        Backward,
        Left,
        Right,
        Jump,
        Duck,
        Extra1,
        Extra2
    };

    //! InputStateEnum
    /*! This enum tells what the event on the input was */
    enum InputStateEnum {
        Pressed,
        Released
    };
}

#endif //INC_2DGAME_ENUMS_H
