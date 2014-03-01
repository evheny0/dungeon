#include "AssetManager.h"

AssetManager::AssetManager()
{
    
}

AssetManager::~AssetManager()
{
    
}

Image *AssetManager::getImage(ImageID &image)
{
    return graphics.getImage(image);
}
