//
// Created by wouter on 6/16/19.
//

#ifndef INC_2DGAME_SCENE_H
#define INC_2DGAME_SCENE_H


namespace GameSpace{
    class Scene {
    public:
        //! Update function
        /*!
         * This function is to be called periodically to update the members of the scene.
         * As long as it is being called it will show the current scene.
         * @param timeTook : The time since the last time calling this function.
         * @return returns 0 if everything is normal. returns score or 1 if done.
         */
        virtual int Update(int timeTook)=0;
    };
}



#endif //INC_2DGAME_SCENE_H
