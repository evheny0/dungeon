#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <list>
#include "graphic/Image.h"
#include "graphic/Tileset.h"
#include "CoreTypes.h"
#include "map_generator/MapGenerator.h"

class Entity;

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
    Image *floor;
    Image *door;

    Image *border_up;
    Image *border_down;
    Image *border_right;
    Image *border_left;
    Tileset background;

    //std::map<int, Entity *> entityMap;
    std::list<Entity *> mobs;
  public:
    Map(int x, int y);
    ~Map();
    void loadImages();
    void generate(int seed = 0);
    void generateMobs();
    void render();
    MapCell *operator[](int x);
    void clear();
    void update();
    void show();
    void showMobs();
    bool isIntersects(int x, int y);
  private:
    void reallocValues();
};


#include "entity/Skeleton.h"

#endif // MAP_H
