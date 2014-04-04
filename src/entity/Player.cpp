#include "entity/Player.h"

Player::Player() : Entity()
{
    stayRight = Game::assetManager->getImage(stayRightID);
    stayLeft = Game::assetManager->getImage(stayLeftID);
    currentImage = stayRight;
    initAnimation();
    setVelocity(4);
}

Player::~Player()
{
    
}

void Player::initAnimation()
{
    moveRightAnimation = new Animation(*(Game::assetManager->getImage(moveRightID)));
    moveLeftAnimation = new Animation(*(Game::assetManager->getImage(moveLeftID)));
    for (int i = 0; i < 6; i++) {
        moveRightAnimation->addFrame(i * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE * 2);
        moveLeftAnimation->addFrame(i * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE * 2);
    }
    moveRightAnimation->play();
    moveLeftAnimation->play();
}

