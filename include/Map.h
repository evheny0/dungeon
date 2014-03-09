#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "graphic/Image.h"
#include "graphic/Tileset.h"
#include "CoreTypes.h"


class MapCell {
  public:
    MapCell() {};
    ~MapCell() {};
    
};

class Map {
    MapCell **values;
    MapCell emptyCell;
    int sizeX;
    int sizeY;

    Image *floor;
    Tileset background;
  public:
    Map(int x, int y);
    ~Map();
    void render();
    MapCell *operator[](int x);
    void clear();

    void show();
  private:
    void reallocValues();
};


#include "Game.h"

#endif // MAP_H
