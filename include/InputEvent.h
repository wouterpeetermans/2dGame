//
// Created by wouter on 3/25/19.
//

#ifndef INC_2DGAME_INPUTEVENT_H
#define INC_2DGAME_INPUTEVENT_H

#include "Enums.h"

namespace GameSpace {
    class InputEvent {
    public:
        InputEvent(InputEnum input, InputStateEnum inputState);
        InputEnum getInput();
        InputStateEnum getType();

    private:
        InputEnum input;
        InputStateEnum inputState;
    };
}


#endif //INC_2DGAME_INPUTEVENT_H
