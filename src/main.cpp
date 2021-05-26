#include <iostream>
#include <Engine/game_object.hpp>
#include <Engine/game.hpp>
#include <Breakout/paddle.hpp>
#include <Breakout/ball.hpp>
#include <Breakout/brick.hpp>

const int COLUMNS = 5;
const int ROWS = 3;
const int BRICKS_OFFSET_X = 65;
const int BRICKS_OFFSET_Y = 35;

int main()
{
    Engine::Game *game = new Engine::Game();
    game->init();

    game->registerGameObject(new Breakout::Paddle());
    game->registerGameObject(new Breakout::Ball());

    for (int i = -3; i < 4; ++i)
    {
        for (int j = -2; j < 2; ++j)
        {
            Breakout::Brick *brick = new Breakout::Brick(j+3);
            game->registerGameObject(brick);
            brick->setPosition(game->getWindowSize().w / 2 - i * BRICKS_OFFSET_X, game->getWindowSize().h / 2 - 100 - j * BRICKS_OFFSET_Y);
        }
    }

    while (game->isRunning)
    {
        game->handleEvents();
        game->update();
        game->render();
        // SDL_Delay(150);
    }

    return 0;
}
