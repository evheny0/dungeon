#include "entity/Skeleton.h"


Skeleton::Skeleton(int _x, int _y) : Entity()
{
    currentImage = Game::assetManager->getImage(skeletonID);
    stayRight = currentImage;
    stayLeft = currentImage;

    ai = new AgressiveAI(this);
    setVelocity(1);

    setPosition(_x, _y);


    moveRightAnimation = new Animation(*(Game::assetManager->getImage(moveRightID)));
    moveLeftAnimation = new Animation(*(Game::assetManager->getImage(moveLeftID)));
    for (int i = 0; i < 6; i++) {
        moveRightAnimation->addFrame(i * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE * 2);
        moveLeftAnimation->addFrame(i * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE * 2);
    }
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
