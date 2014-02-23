#include "graphics.h"

Image::Image(std::string path)
{
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

Image::~Image()
{

}

void Image::setPosition(int x, int y)
{
    sprite.setPosition(sf::Vector2f(x, y));
}

void Image::show()
{
    window->draw(sprite);
}
