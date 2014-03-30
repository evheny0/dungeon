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
