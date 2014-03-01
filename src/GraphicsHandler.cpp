#include "GraphicsHandler.h"

GraphicsHandler::GraphicsHandler()
{
    images[splashID] = new Image(splashID);
    images[charachterID] = new Image(charachterID);
}

GraphicsHandler::~GraphicsHandler()
{
    
}

Image *GraphicsHandler::getImage(ImageID &image)
{
    Image *returnImage = images[image];
    if (!returnImage) {
        throw "Image not found";
    }
    return returnImage;
}
