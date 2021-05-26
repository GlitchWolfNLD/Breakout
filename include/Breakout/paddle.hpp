#include <iostream>
#include <Engine/game_object.hpp>

#pragma once

namespace Breakout
{
    class Paddle : public Engine::GameObject
    {
        const int PADDLE_WITH = 40;
        const int PADDLE_HEIGHT = 10;

        const int PADDLE_COLOR[4] = {255,255,255,255};

        const int PADDLE_MOVE_SPEED = 5;

    public:
        void init(Engine::Game *game) override;

        void handleEvents(SDL_Event *e) override;

        void update() override;

        void render() override;
    };
}