#ifndef GRAPHICS_HANDLER_H
#define GRAPHICS_HANDLER_H

#include <map>
#include "Assets.h"
#include "BasicHandler.h"
#include "Graphics.h"


class GraphicsHandler : public BasicHandler {
    std::map<ImageID, Image *> images;
  public:
    GraphicsHandler();
    ~GraphicsHandler();
    Image *getImage(ImageID &image);
};

#endif
