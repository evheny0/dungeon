#ifndef GRAPHICS_HANDLER_H
#define GRAPHICS_HANDLER_H

#include <map>
#include "Assets.h"
#include "BasicHandler.h"
#include "graphic/Image.h"
#include "graphic/Drawable.h"


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
