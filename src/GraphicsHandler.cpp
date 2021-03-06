#include "GraphicsHandler.h"

GraphicsHandler::GraphicsHandler()
{
    textures[splashID] = newTexture(splashID);
    textures[buttonID] = newTexture(buttonID);
    textures[button_inactiveID] = newTexture(button_inactiveID);

    textures[floorID] = newTexture(floorID);
    textures[wallID] = newTexture(wallID);
    textures[wallDownID] = newTexture(wallDownID);
    textures[doorID] = newTexture(doorID);

    textures[borderUpID] = newTexture(borderUpID);
    textures[borderDownID] = newTexture(borderDownID);
    textures[borderRightID] = newTexture(borderRightID);
    textures[borderLeftID] = newTexture(borderLeftID);

    textures[moveRightID] = newTexture(moveRightID);
    textures[moveLeftID] = newTexture(moveLeftID);
    textures[stayRightID] = newTexture(stayRightID);
    textures[stayLeftID] = newTexture(stayLeftID);

    textures[skeletonID] = newTexture(skeletonID);
}

GraphicsHandler::~GraphicsHandler()
{
    std::map<ImageID, sf::Texture *>::iterator it;
    for (it = textures.begin(); it != textures.end(); ++it) {
        delete it->second;
    }
}
#include <iostream>
sf::Texture *GraphicsHandler::getSfmlTexture(ImageID imageID)
{
    sf::Texture *returnTexture = textures[imageID];
    if (!returnTexture) {
        throw "Texture not found";
    }
    return returnTexture;
}


sf::Texture *GraphicsHandler::newTexture(ImageID path)
{
    sf::Texture *returnTexture = new sf::Texture();
    returnTexture->loadFromFile(path);
    return returnTexture;
}
