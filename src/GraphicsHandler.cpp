#include "GraphicsHandler.h"

GraphicsHandler::GraphicsHandler()
{
    images[splashID] = new Image(splashID);
    images[charachterID] = new Image(charachterID);
}

GraphicsHandler::~GraphicsHandler()
{
    std::map<ImageID, Image *>::iterator it;
    for (it = images.begin(); it != images.end(); ++it) {
        delete it->second;
    }
}

Image *GraphicsHandler::getImage(ImageID &image)
{
    Image *returnImage = images[image];
    if (!returnImage) {
        throw "Image not found";
    }
    return returnImage;
}
