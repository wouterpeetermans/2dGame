//
// Created by wouter on 6/16/19.
//

#include "SpeedVector.h"

namespace GameSpace{

    int SpeedVector::xDir(){
        if (x < 0) {
            return 1;
        }
        else if(x > 0){
            return -1;
        }
        else {
            return 0;
        }
    }


    int SpeedVector::yDir(){
        if (y < 0) {
            return 1;
        }
        else if(y > 0){
            return -1;
        }
        else {
            return 0;
        }
    }

    void SpeedVector::operator+=(const SpeedVector& other){
        x += other.x;
        y += other.y;
    }

    void SpeedVector::xInvert(){
        x*=-1;
    }

    void SpeedVector::yInvert(){
        y*=-1;
    }
     SpeedVector SpeedVector::operator*(double number){
        SpeedVector result;
        result.x = number*x;
        result.y = number*y;
        return result;
    }
}