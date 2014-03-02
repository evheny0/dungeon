#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "GraphicsHandler.h"
#include "FontHandler.h"
#include "Image.h"
#include "Text.h"


class AssetManager {
    GraphicsHandler graphics;
    FontHandler fonts;
  public:
    AssetManager();
    ~AssetManager();
    Image *getImage(ImageID &image);
    Text *getText(FontID &font);
};

#endif
