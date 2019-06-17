//
// Created by wouter on 3/4/19.
//

#ifndef INC_2DGAME_GAMEOBJECT_H
#define INC_2DGAME_GAMEOBJECT_H

#include <memory>
#include <list>
#include "Enums.h"

namespace GameSpace {
    class GameObject {
    public:
        GameObject(int Xpos, int Ypos);

        virtual void Update(int timeTook) = 0;

        virtual ~GameObject() = default;

        virtual CollisionEnum Collides(const GameObject* object);

        virtual void DetectCollisions(
                std::shared_ptr<std::list<std::shared_ptr<GameObject>>> coliderList){};

        int getxPos() const;

        int getyPos() const;

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);


        bool isDestroyed();


    protected:
        void setDestroyed();
        int xPos;
        int yPos;
        int width;
        int height;
    private:
        bool isDestroyedBool;
    };
}

#endif //INC_2DGAME_GAMEOBJECT_H
