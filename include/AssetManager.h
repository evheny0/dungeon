#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "GraphicsHandler.h"
#include "FontHandler.h"


class AssetManager {
    GraphicsHandler graphics;
    FontHandler fonts;
  public:
    AssetManager();
    ~AssetManager();
    sf::Texture *getSfmlTexture(ImageID imageID);
    sf::Font *getSfmlFont(FontID fontID);
};


#endif
