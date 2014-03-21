#include "entity/Player.h"

Player::Player()
{
    stayRight = Game::assetManager->getImage(stayRightID);
    stayLeft = Game::assetManager->getImage(stayLeftID);
    currentImage = stayRight;
    initAnimation();
    setVelocity(4);
    setPosition(0, 0);
    stop();
}

Player::~Player()
{
    
}

void Player::initAnimation()
{
    moveRightAnimation = new Animation(*(Game::assetManager->getImage(moveRightID)));
    moveLeftAnimation = new Animation(*(Game::assetManager->getImage(moveLeftID)));
    for (int i = 0; i < 8; i++) {
        moveRightAnimation->addFrame(i * 32, 0, 32, 82);
        moveLeftAnimation->addFrame(i * 32, 0, 32, 82);
    }
    moveRightAnimation->play();
    moveLeftAnimation->play();
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

void Player::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Player::setVelocity(int vel)
{
    velocity = vel;
}


void Player::stop()
{
    dx = 0;
    dy = 0;
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

void Player::move()
{
    y += dy;
    x += dx;
}

void Player::rollback()
{
    y -= dy;
    x -= dx;
}


void Player::show()
{
    currentImage->setPosition(x - (currentImage->getWidth() / 2), y - currentImage->getHeight());
    currentImage->show();
}
