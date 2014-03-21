#include "GraphicsHandler.h"

GraphicsHandler::GraphicsHandler()
{
    textures[splashID] = newTexture(splashID);
    textures[buttonID] = newTexture(buttonID);
    textures[button_inactiveID] = newTexture(button_inactiveID);

    textures[floorID] = newTexture(floorID);
    textures[wallID] = newTexture(wallID);
    textures[wallDownID] = newTexture(wallDownID);
    textures[wallSideID] = newTexture(wallSideID);
    textures[doorID] = newTexture(doorID);

    textures[moveRightID] = newTexture(moveRightID);
    textures[moveLeftID] = newTexture(moveLeftID);
    textures[stayRightID] = newTexture(stayRightID);
    textures[stayLeftID] = newTexture(stayLeftID);
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
