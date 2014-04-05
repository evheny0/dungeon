#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Drawable {
  public:
    static sf::RenderWindow *window;
    static AssetManager *assetManager;
    virtual void show() = 0;
    virtual ~Drawable() { };
};




#endif // DRAWABLE_H
