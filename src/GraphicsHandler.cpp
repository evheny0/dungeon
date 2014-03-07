#include "GraphicsHandler.h"

GraphicsHandler::GraphicsHandler()
{
    textures[splashID] = newTexture(splashID);
    textures[charachterID] = newTexture(charachterID);
    textures[buttonID] = newTexture(buttonID);
    textures[button_inactiveID] = newTexture(button_inactiveID);
    textures[floorID] = newTexture(floorID);
}

GraphicsHandler::~GraphicsHandler()
{
    std::map<ImageID, sf::Texture *>::iterator it;
    for (it = textures.begin(); it != textures.end(); ++it) {
        delete it->second;
    }
}

Image *GraphicsHandler::getImage(ImageID &image)
{
    sf::Texture *currentTexture = textures[image];
    if (!currentTexture) {
        throw "Image not found";
    }
    return new Image(*currentTexture);
}



sf::Texture *GraphicsHandler::newTexture(ImageID path)
{
    sf::Texture *returnTexture = new sf::Texture();
    returnTexture->loadFromFile(path);
    return returnTexture;
}
