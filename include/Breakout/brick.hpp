#include <iostream>
#include <Engine/game_object.hpp>

#pragma once

namespace Breakout{
    class Brick : public Engine::GameObject{
    private:
        int type = 1;

    public:
        Brick(int type);

        void init(Engine::Game *game) override;

        void update() override;

        void render() override;
    };
}