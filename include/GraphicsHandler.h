#ifndef GRAPHICS_HANDLER_H
#define GRAPHICS_HANDLER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "Assets.h"
#include "BasicHandler.h"


class GraphicsHandler : public BasicHandler {
    std::map<ImageID, sf::Texture *> textures;

  public:
    GraphicsHandler();
    ~GraphicsHandler();
    sf::Texture *getSfmlTexture(ImageID imageID);

  private:
    sf::Texture *newTexture(ImageID path);
};

#endif
