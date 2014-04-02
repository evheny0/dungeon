#include "entity/Entity.h"

Entity::Entity()
{
    setVelocity(4);
    setPosition(0, 0);
    stop();
    currentImage = 0;
}

Entity::~Entity()
{

}



int Entity::getX()
{
    return x;
}

int Entity::getY()
{
    return y;
}

void Entity::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Entity::setVelocity(int vel)
{
    velocity = vel;
}

void Entity::stop()
{
    dx = 0;
    dy = 0;
}

void Entity::move()
{
    y += dy;
    x += dx;
}

void Entity::rollback()
{
    y -= dy;
    x -= dx;
}

void Entity::show()
{
    currentImage->setPosition(x - (currentImage->getWidth() / 2), y - currentImage->getHeight());
    currentImage->show();
}


bool isEnemy(Entity *opponent)
{
    return true;
}

        /*
         *  Need to rewrite
         */

void Entity::runUp()
{
    dy -= velocity;
    if (currentImage == stayRight || currentImage == moveRightAnimation) {
        currentImage = moveRightAnimation;
    } else {
        currentImage = moveLeftAnimation;
    }
}

void Entity::runDown()
{
    dy += velocity;
    if (currentImage == stayLeft || currentImage == moveLeftAnimation) {
        currentImage = moveLeftAnimation;
    } else {
        currentImage = moveRightAnimation;
    }
}

void Entity::runRight()
{
    dx += velocity;
    currentImage = moveRightAnimation;
}

void Entity::runLeft()
{
    dx -= velocity;
    currentImage = moveLeftAnimation;
}


void Entity::stopUp()
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

void Entity::stopDown()
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

void Entity::stopRight()
{
    dx -= velocity;
    if (dy == 0) {
        currentImage = stayRight;
    }
}

void Entity::stopLeft()
{
    dx += velocity;
    if (dy == 0) {
        currentImage = stayLeft;
    }
}
