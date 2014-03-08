#include "Tileset.h"

Tileset::Tileset(int x, int y)
{
    renderTexture.create(500, 500);
    clear();
}

Tileset::~Tileset()
{

}

void Tileset::clear()
{
    renderTexture.clear();
}

void Tileset::draw(Image *image, int x, int y)
{
    image->setPosition(x, y);
    renderTexture.draw(image->getSfmlSprite());
}

void Tileset::formImage()
{
    renderTexture.display();
    texture = renderTexture.getTexture();
    sprite.setTexture(texture);
}

void Tileset::show()
{
    window->draw(sprite);
}
