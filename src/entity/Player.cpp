#include "entity/Player.h"

Player::Player()
{
    image = Game::assetManager->getImage(charachterID);
}

Player::~Player()
{

}



void Player::setPosition(int x, int y)
{
    image->setPosition(x, y);
}

void Player::show()
{
    image->show();
}
