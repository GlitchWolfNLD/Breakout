#include <iostream>
#include <Engine/game_object.hpp>

#pragma once

namespace Breakout 
{
    class Ball : public Engine::GameObject
    {
        const int SPEED = 3;

        //size of the sprite, this is a multiplier 
        //(i.e. if the original size is 32x32 and size is 2 than the rendered size will be 64x64)
        const int SIZE = 2;

    private:
        double deltatime = 0.0;
        
        bool spawned = false;

    public:
        void init(Engine::Game *game) override;

        void update() override;

        void render() override;

        void handleEvents(SDL_Event *e) override;

        void spawn();

        void gameOver();
    };
}
