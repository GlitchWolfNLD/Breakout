#include <Breakout/paddle.hpp>

using namespace Breakout;

void Paddle::init(Engine::Game *game)
{
    GameObject::init(game);
    
    texture->loadFromFile("paddle.png");

    Engine::WindowSize windowSize = game->getWindowSize();
    //initial x position is in the middle of the screen
    x = windowSize.w/2; 
    //y is fixed
    y = windowSize.h - 100;

    SDL_Rect collider = {x,y, texture->getWidth(), texture->getHeight()};
    this->collider = collider;

    originX = texture->getWidth() / 2;
    originY = texture->getHeight() / 2;
}

void Paddle::handleEvents(SDL_Event *e)
{

}

void Paddle::update()
{
    GameObject::update();

    const Uint8 *kb = SDL_GetKeyboardState(NULL);

    //update x with keyboard input
    x += (kb[SDL_SCANCODE_RIGHT] - kb[SDL_SCANCODE_LEFT]) * PADDLE_MOVE_SPEED;
}

void Paddle::render()
{
    GameObject::render();
}