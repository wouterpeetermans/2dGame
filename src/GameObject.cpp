//
// Created by wouter on 3/4/19.
//

#include <include/GameObject.h>

#include "GameObject.h"

namespace GameSpace {

    GameObject::GameObject(int Xpos, int Ypos) {
        this->xPos = Xpos;
        this->yPos = Ypos;
        isDestroyedBool = false;
    }

    int GameObject::getxPos() const {
        return xPos;
    }

    int GameObject::getyPos() const {
        return yPos;
    }

    bool GameObject::isDestroyed() {
        return isDestroyedBool;
    }

    void GameObject::setDestroyed() {
        isDestroyedBool = true;
    }
}
