#ifndef TILESET_H
#define TILESET_H

#include <string>
#include <SFML/Graphics.hpp>
#include "graphic/Image.h"
#include "graphic/Drawable.h"


class Tileset : public Drawable {
    sf::RenderTexture renderTexture;
    int sizeX, sizeY;
    sf::Texture texture;
    sf::Sprite sprite;
  public:
    Tileset(int x, int y);
    ~Tileset();
    void clear();
    void draw(Image *image, int x, int y);
    void formImage();
    void show();
};

#endif // TILESET_H
