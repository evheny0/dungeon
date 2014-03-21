#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "graphic/Image.h"
#include "graphic/Tileset.h"
#include "CoreTypes.h"
#include "map_generator/MapGenerator.h"


class MapCell {
  public:
    MapCell() {};
    ~MapCell() {};
    
};

class Map {
    MapGenerator generator;
    MapCell **values;
    MapCell emptyCell;
    MapCell wallCell;
    MapCell floorCell;
    int sizeX;
    int sizeY;

  public:
    int startX;
    int startY;

  private:
    Image *wall;
    Image *wallDown;
    Image *wallSide;
    Image *floor;
    Image *door;
    Tileset background;
  public:
    Map(int x, int y);
    ~Map();
    void generate(int seed = 0);
    void render();
    MapCell *operator[](int x);
    void clear();
    void show();
    bool isIntersects(int x, int y);
  private:
    void reallocValues();
};


#include "Game.h"

#endif // MAP_H
