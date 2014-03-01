#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "GraphicsHandler.h"
#include "Graphics.h"

class AssetManager {
    GraphicsHandler graphics;
  public:
    AssetManager();
    ~AssetManager();
    Image *getImage(ImageID &image);
};

#endif
