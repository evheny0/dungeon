#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <SFML/Graphics.hpp>


class Image {
    std::string path;
    sf::Texture texture;
    sf::Sprite sprite;
  public:
    static sf::RenderWindow *window;
  public:
    Image(std::string path);
    ~Image();
    void setPosition(int x, int y);
    void show();
};


#endif