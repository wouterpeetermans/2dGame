//
// Created by wouter on 3/25/19.
//


#include "InputEvent.h"

namespace GameSpace {
    InputEvent::InputEvent(GameSpace::InputEnum input, GameSpace::InputStateEnum inputState) {
        this->input = input;
        this->inputState = inputState;
    }

    InputEnum GameSpace::InputEvent::getInput() {
        return this->input;
    }

    InputStateEnum GameSpace::InputEvent::getType() {
        return this->inputState;
    }
}


