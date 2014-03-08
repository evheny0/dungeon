#include "entity/Player.h"

Player::Player()
{
    image = Game::assetManager->getImage(charachterID);
    setVelocity(3);
    setPosition(0, 0);
}

Player::~Player()
{

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

void Player::moveUp()
{
    y -= velocity;
}

void Player::moveDown()
{
    y += velocity;
}

void Player::moveRight()
{
    x += velocity;
}

void Player::moveLeft()
{
    x -= velocity;
}

void Player::show()
{
    std::cout << x << " " << y << "\n";
    image->setPosition(x, y);
    image->show();
}