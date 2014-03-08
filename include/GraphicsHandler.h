#ifndef GRAPHICS_HANDLER_H
#define GRAPHICS_HANDLER_H

#include <map>
#include "Assets.h"
#include "BasicHandler.h"
#include "Image.h"
#include "Drawable.h"


class GraphicsHandler : public BasicHandler {
    std::map<ImageID, sf::Texture *> textures;

  public:
    GraphicsHandler();
    ~GraphicsHandler();
    Image *getImage(ImageID &image);

  private:
    sf::Texture *newTexture(ImageID path);
};

#endif
