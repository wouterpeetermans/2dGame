//
// Created by wouter on 3/11/19.
//

#ifndef INC_2DGAME_SDLFACTORY_H
#define INC_2DGAME_SDLFACTORY_H

#include "AFactory.h"
#include "SdlDrawEngine.h"

namespace SDLSpace {
    class SdlFactory : public GameSpace::AFactory {

    public:
        SdlFactory();

        ~SdlFactory() override;

        std::shared_ptr<GameSpace::Player> CreatePlayer(int beginSpeed) override;

        std::shared_ptr<GameSpace::DrawEngine> GetDrawEngine() override;

        std::shared_ptr<GameSpace::GameObject> CreateRoad(
                std::shared_ptr<GameSpace::GameObject> player) override;

        std::shared_ptr<GameSpace::GameObject> CreateMiniVan(int xPos, int yPos, int speed) override;

        std::shared_ptr<GameSpace::Scene> CreateGameScene(std::shared_ptr<AFactory> factory) override;

        std::shared_ptr<GameSpace::GameObject> CreatePoliceCar(int xPos, int yPos, int speed,
                                                               std::shared_ptr<std::list<std::shared_ptr<GameSpace::GameObject>>> objectList) override;

    private:
        std::shared_ptr<SdlDrawEngine> drawEngine;
    };
}


#endif //INC_2DGAME_SDLFACTORY_H
