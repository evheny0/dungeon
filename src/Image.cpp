#include "Image.h"

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

int Image::getWidth()
{
    return sprite.getTextureRect().width;
}

int Image::getHeight()
{
    return sprite.getTextureRect().height;
}

sf::Rect<int> Image::getTextureRect()
{
    return sprite.getTextureRect();
}
