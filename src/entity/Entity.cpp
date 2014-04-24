#include "entity/Entity.h"

Entity::Entity()
{
    setPosition(0, 0);
    stop();
    currentImage = 0;
    health = 0;
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

void Entity::setDx(int _dx)
{
    dx = _dx;
}

void Entity::setDy(int _dy)
{
    dy = _dy;
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
    currentImage = stayRight;
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

void Entity::heal(int value)
{
    if (value == 0 || (value + health) > maxHealth) {
        health = maxHealth;
    } else {
        health += value;
    }
}

void Entity::hurt(int value)
{
    if ((health - value) < 0) {
        health = 0;
    } else {
        health -= value;
    }
}

void Entity::show() 
{
    currentImage->setPosition(x - (currentImage->getWidth() / 2), y - currentImage->getHeight());
    currentImage->show();
}

bool Entity::isEnemy(Entity *opponent)
{
    return true;
}

void Entity::setDestination(int _destX, int _destY)
{
    destX = _destX;
    destY = _destY;
    if (_destX != x || _destY != y) {
        calculateVector();
    }
}

void Entity::calculateVector() 
{
    if (abs(destX - x) < 0.000001) {
        dx = 0;
        dx = velocity;
    } else if (abs(destY - y) < 0.000001) {
        dx = velocity;
        dy = 0;
    } else {
        float floatdy, floatdx, ratio = (float) abs(destX - x) / (float) abs(destY - y);
        floatdy = velocity / (sqrt(ratio * ratio + 1));
        floatdx = sqrt((float) (velocity * velocity) - floatdy * floatdy);
        dy = roundf(floatdy);
        dx = roundf(floatdx);
    }
    if (x > destX) {
        dx = -dx;
    }
    if (y > destY) {
        dy = -dy;
    }
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
