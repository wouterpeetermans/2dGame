//
// Created by wouter on 3/4/19.
//

#ifndef INC_2DGAME_GAMEOBJECT_H
#define INC_2DGAME_GAMEOBJECT_H

#include <memory>
#include <list>

namespace GameSpace {
    class GameObject {
    public:
        GameObject(int Xpos, int Ypos);

        virtual void Update(int timeTook) = 0;

        virtual ~GameObject() = default;

        int getXpos() const;

        int getYpos() const;

        bool isDestroyed();


    protected:
        void setDestroyed();
        int Xpos;
        int Ypos;
    private:
        bool isDestroyedBool;
    };
}

#endif //INC_2DGAME_GAMEOBJECT_H
