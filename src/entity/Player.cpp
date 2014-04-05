#include "entity/Player.h"

Player::Player() : Entity()
{
    stayRight = new Image(stayRightID);
    stayLeft = new Image(stayLeftID);
    currentImage = stayRight;
    initAnimation();
    setVelocity(4);
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

void Player::act(Map *levelMap)
{
    (*levelMap)[x / TILE_SIZE][y / TILE_SIZE].removeEntity(this);
    move();
    if (levelMap->isIntersects(x / TILE_SIZE, y / TILE_SIZE)) {
        rollback();
    }
    (*levelMap)[x / TILE_SIZE][y / TILE_SIZE].addEntity(this);
}
