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

Text *AssetManager::getText(FontID &font)
{
    return fonts.getText(font);
}
