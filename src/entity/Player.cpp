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
    for (int i = 0; i < 6; i++) {
        moveRightAnimation->addFrame(i * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE * 2);
        moveLeftAnimation->addFrame(i * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE * 2);
    }
    moveRightAnimation->play();
    moveLeftAnimation->play();
}

void Player::act(Map *levelMap)
{
    move();
    if (levelMap->isIntersects(x / TILE_SIZE, y / TILE_SIZE)) {
        rollback();
    }
}
