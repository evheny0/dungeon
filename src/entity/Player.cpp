#include "entity/Player.h"

Player::Player() : Entity()
{
    stayRight = new Image(stayRightID);
    stayLeft = new Image(stayLeftID);
    currentImage = stayRight;
    initAnimation();
    setVelocity(4);
    maxHealth = 10;
    heal();
}

Player::~Player()
{
    
}

void Player::initAnimation()
{
    moveRightAnimation = new Animation(moveRightID);
    moveLeftAnimation = new Animation(moveLeftID);
    moveRightAnimation->split(TILE_SIZE);
    moveLeftAnimation->split(TILE_SIZE);
    moveRightAnimation->play();
    moveLeftAnimation->play();
}

void Player::input(sf::Event &event)
{
    inputEvent(event);
}

void Player::eventKeyPressed(sf::Event::KeyEvent &key)
{
    switch (key.code) {
    case sf::Keyboard::W:
        runUp();
        break;
    case sf::Keyboard::A:
        runLeft();
        break;
    case sf::Keyboard::S:
        runDown();
        break;
    case sf::Keyboard::D:
        runRight();
        break;
    }
}

void Player::eventKeyReleased(sf::Event::KeyEvent &key)
{
    switch (key.code) {
    case sf::Keyboard::W:
        stopUp();
        break;
    case sf::Keyboard::A:
        stopLeft();
        break;
    case sf::Keyboard::S:
        stopDown();
        break;
    case sf::Keyboard::D:
        stopRight();
        break;
    }
}

void Player::eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton)
{

}

void Player::act(Map *levelMap)
{
    (*levelMap)[x / TILE_SIZE][y / TILE_SIZE].removeEntity(this);
    move();
    if (levelMap->isIntersects(x / TILE_SIZE, y / TILE_SIZE)) {
        rollback();
    }
    (*levelMap)[x / TILE_SIZE][y / TILE_SIZE].addEntity(this);
}
