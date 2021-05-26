#include <Breakout/ball.hpp>
#include <SDL2/SDL_image.h>
#include <Breakout/paddle.hpp>

using namespace Breakout;

void Ball::init(Engine::Game *game)
{
    GameObject::init(game);
}

void Ball::spawn()
{
    texture->loadFromFile("ball.png", SIZE);

    Engine::WindowSize windowSize = game->getWindowSize();
    x = windowSize.w / 2;
    y = windowSize.h / 2;

    dx = rand() % 6 - 3;
    dy = 3;

    // angle = -2.0/3.0 * M_PI;

    originX = texture->getWidth() / 2;
    originY = texture->getHeight() / 2;

    SDL_Rect collider = {x, y, texture->getWidth(), texture->getHeight()};
    this->collider = collider;

    this->spawned = true;
}

void Ball::handleEvents(SDL_Event *e)
{
    switch (e->type)
    {
    case SDL_MOUSEBUTTONDOWN:
        switch (e->button.button)
        {
        case SDL_BUTTON_LEFT:
            spawn();
            break;
        }
        break;
    }
}

void Ball::update()
{
    GameObject::update();

    if (!spawned)
        return;

    //update position
    x += dx;
    y += dy;

    if (deltatime > 0.0)
    {
        deltatime -= 0.1;
        return;
    }

    if(x - texture->getWidth() / 2 < 0) {dx *= -1; deltatime+=0.2;}
    if(x + texture->getWidth() / 2 > game->getWindowSize().w) {dx *= -1; deltatime+=0.2;}
    if(y - texture->getWidth() / 2 < 0) {dy *= -1; deltatime+=0.2;}
    if(y + texture->getWidth() / 2 > game->getWindowSize().h) {gameOver(); deltatime+=0.2;}

    GameObject *collidingObject = game->isOverlappingAny(&collider, NULL);
    if (collidingObject != nullptr)
    {
        Paddle *paddle = dynamic_cast<Paddle *>(collidingObject);
        //hit the paddle
        if (paddle != nullptr)
        {
            dx = (x - paddle->getX()) / 6;
            dy *= -1;
        }
        else
        {
            //hit object from the left or right side
            if (x > collidingObject->getX() + collidingObject->getTexture()->getWidth() / 2 || x < collidingObject->getX() - collidingObject->getTexture()->getWidth() / 2)
            {
                dx *= -1;
            }
            //hit object from top or bottom
            if (y > collidingObject->getY() + collidingObject->getTexture()->getHeight() / 2 || y < collidingObject->getY() - collidingObject->getTexture()->getHeight() / 2)
            {
                dy *= -1;
            }
            //destroy the object
            game->deRegisterGameObject(collidingObject);
        }
        deltatime += 0.2;
    }
}

void Ball::gameOver(){}

void Ball::render()
{
    GameObject::render();
}