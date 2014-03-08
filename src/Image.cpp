#include "Image.h"

Image::Image(std::string path)
{
    texture.loadFromFile(path);
    sprite.setTexture(texture, true);
}

Image::Image(sf::Texture &texture)
{
    this->texture = texture;
    sprite.setTexture(texture);
}

Image::~Image()
{

}

sf::Sprite &Image::getSfmlSprite()
{
    return sprite;
}

void Image::setPosition(int x, int y)
{
    sprite.setPosition(x, y);
}

void Image::move(int x, int y)
{
    sprite.move(x, y);
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
    sf::Rect<int> out;
    out = sprite.getTextureRect();
    out.left = sprite.getPosition().x;
    out.top = sprite.getPosition().y;
    return out;
}
