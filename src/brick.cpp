#include <Breakout/brick.hpp>

using namespace Breakout;

Brick::Brick(int type) : GameObject(){
    this->type = type;
}

void Brick::init(Engine::Game *game){
    GameObject::init(game);

    std::string path = "brick" + std::to_string(type) + ".png";
    texture->loadFromFile(path, 2);

    originX = texture->getWidth() / 2;
    originY = texture->getHeight() / 2;

    SDL_Rect collider = {x, y, texture->getWidth(), texture->getHeight()};
    this->collider = collider;
}

void Brick::update(){
    GameObject::update();
}

void Brick::render(){
    GameObject::render();
}