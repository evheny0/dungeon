#include "entity/Skeleton.h"


Skeleton::Skeleton()
{
    currentImage = Game::assetManager->getImage(skeletonID);
}

Skeleton::~Skeleton()
{

}
