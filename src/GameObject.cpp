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

    int GameObject::getWidth() const {
        return width;
    }

    void GameObject::setWidth(int width) {
        GameObject::width = width;
    }

    int GameObject::getHeight() const {
        return height;
    }

    void GameObject::setHeight(int height) {
        GameObject::height = height;
    }

    CollisionEnum GameObject::Collides(const GameObject* object) {
        if (object == this)
            return NONE;
        int thisUp, thisDown, thisLeft, thisRight, objectUp, objectDown, objectLeft, objectRight;
        thisUp = this->yPos + (this->height/2);
        thisDown = this->yPos - (this->height/2);
        thisLeft = this->xPos - (this->width/2);
        thisRight = this->xPos + (this->width/2);
        objectUp = object->getyPos() + (object->getHeight()/2);
        objectDown = object->getyPos() - (object->getHeight()/2);
        objectLeft = object->getxPos() - (object->getWidth()/2);
        objectRight = object->getxPos() + (object->getWidth()/2);
        if(thisRight > objectLeft && thisLeft < objectRight){
            if(thisUp > objectDown && thisDown < objectUp){
                return EVENT;
            }
        }
        return NONE;
    }
}
