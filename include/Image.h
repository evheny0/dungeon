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
    Image(sf::Texture &texture);
    ~Image();
    void setPosition(int x, int y);
    void move(int x, int y);
    void show();
    int getWidth();
    int getHeight();
    sf::Rect<int> getTextureRect();
};


#endif
