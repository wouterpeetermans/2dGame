//
// Created by wouter on 3/4/19.
//

#include <include/GameObject.h>

#include "GameObject.h"

namespace GameSpace {

    GameObject::GameObject(int Xpos, int Ypos) {
        this->Xpos = Xpos;
        this->Ypos = Ypos;
    }

    int GameObject::getXpos() const {
        return Xpos;
    }

    int GameObject::getYpos() const {
        return Ypos;
    }
}