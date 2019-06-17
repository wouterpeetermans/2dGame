//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_SPEEDVECTOR_H
#define INC_2DGAME_SPEEDVECTOR_H

namespace GameSpace {
    class SpeedVector {
    private:
        int x , y;
    public:
        SpeedVector() : x(0) , y(0) {};
        SpeedVector(int a,int b) : x(a) , y(b) {};
        int xDir();
        int yDir();
        int xSpeed(){return x;};
        int ySpeed(){return y;};
        void xZero() {x = 0;};
        void yZero() {y = 0;};
        void xInvert();
        void yInvert();
        void operator+= (const SpeedVector&);
        void setxSpeed(int a);
        void setySpeed(int a);
        SpeedVector operator* (double);
    };
}




#endif //INC_2DGAME_SPEEDVECTOR_H
