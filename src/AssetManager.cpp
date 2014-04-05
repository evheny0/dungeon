#include "AssetManager.h"

AssetManager::AssetManager()
{
    
}

AssetManager::~AssetManager()
{
    
}

sf::Texture *AssetManager::getSfmlTexture(ImageID imageID)
{
    return graphics.getSfmlTexture(imageID);
}

sf::Font *AssetManager::getSfmlFont(FontID fontID)
{
    return fonts.getSfmlFont(fontID);
}
