#include "entity/Skeleton.h"


Skeleton::Skeleton(int _x, int _y) : Entity()
{
    currentImage = new Image(skeletonID);
    stayRight = currentImage;
    stayLeft = currentImage;

    ai = new AgressiveAI(this);
    setVelocity(2);

    setPosition(_x, _y);


    moveRightAnimation = new Animation(moveRightID);
    moveLeftAnimation = new Animation(moveLeftID);
    moveRightAnimation->split(TILE_SIZE);
    moveLeftAnimation->split(TILE_SIZE);
    moveRightAnimation->play();
    moveLeftAnimation->play();
}

Skeleton::~Skeleton()
{

}

void Skeleton::act(Map *levelMap)
{
    ai->updateState(levelMap);
}
