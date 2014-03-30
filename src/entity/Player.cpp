#include "entity/Player.h"

Player::Player() : Entity()
{
    stayRight = Game::assetManager->getImage(stayRightID);
    stayLeft = Game::assetManager->getImage(stayLeftID);
    currentImage = stayRight;
    initAnimation();
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

void Player::runUp()
{
    dy -= velocity;
    if (currentImage == stayRight || currentImage == moveRightAnimation) {
        currentImage = moveRightAnimation;
    } else {
        currentImage = moveLeftAnimation;
    }
}

void Player::runDown()
{
    dy += velocity;
    if (currentImage == stayLeft || currentImage == moveLeftAnimation) {
        currentImage = moveLeftAnimation;
    } else {
        currentImage = moveRightAnimation;
    }
}

void Player::runRight()
{
    dx += velocity;
    currentImage = moveRightAnimation;
}

void Player::runLeft()
{
    dx -= velocity;
    currentImage = moveLeftAnimation;
}


void Player::stopUp()
{
    dy += velocity;
    if (dx == 0) {
        if (currentImage == moveLeftAnimation) {
            currentImage = stayLeft;
        } else {
            currentImage = stayRight;
        }
    }
}

void Player::stopDown()
{
    dy -= velocity;
    if (dx == 0) {
        if (currentImage == moveLeftAnimation) {
            currentImage = stayLeft;
        } else {
            currentImage = stayRight;
        }
    }
}

void Player::stopRight()
{
    dx -= velocity;
    if (dy == 0) {
        currentImage = stayRight;
    }
}

void Player::stopLeft()
{
    dx += velocity;
    if (dy == 0) {
        currentImage = stayLeft;
    }
}
