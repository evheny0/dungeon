#include "entity/Player.h"

Player::Player()
{
    image = Game::assetManager->getImage(charachterID);
    setVelocity(3);
    setPosition(0, 0);
    stop();
}

Player::~Player()
{
    
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
    image->setPosition(x, y);
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
}

void Player::runDown()
{
    dy += velocity;
}

void Player::runRight()
{
    dx += velocity;
}

void Player::runLeft()
{
    dx -= velocity;
}

void Player::stopUp()
{
    dy += velocity;
}

void Player::stopDown()
{
    dy -= velocity;
}

void Player::stopRight()
{
    dx -= velocity;
}

void Player::stopLeft()
{
    dx += velocity;
}

void Player::move()
{
    y += dy;
    x += dx;
}


void Player::show()
{
    image->setPosition(x, y);
    image->show();
}
