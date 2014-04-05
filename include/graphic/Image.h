#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <SFML/Graphics.hpp>
#include "graphic/Drawable.h"
#include "Assets.h"


class Image : public Drawable {
    std::string path;
    sf::Texture *texture;
  protected:
    sf::Sprite sprite;
  public:
    Image(sf::Texture &texture);
    Image(const Image &copy);
    Image(ImageID imageID);
    ~Image();
    sf::Sprite &getSfmlSprite();
    sf::Rect<int> getTextureRect();
    void setPosition(int x, int y);
    void move(int x, int y);
    void show();

    virtual int getWidth();
    virtual int getHeight();
};


#endif
