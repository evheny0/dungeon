#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"


class Image : public Drawable {
    std::string path;
    sf::Texture texture;
    sf::Sprite sprite;
  public:
    Image(std::string path);
    Image(sf::Texture &texture);
    ~Image();
    sf::Sprite &getSfmlSprite();
    void setPosition(int x, int y);
    void move(int x, int y);
    void show();
    int getWidth();
    int getHeight();
    sf::Rect<int> getTextureRect();
};


#endif
