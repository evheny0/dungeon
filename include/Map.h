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
    std::list<Entity *> entities;
    bool isPassable;
    Image *image;
  public:
    MapCell(bool _isPassable = false);
    MapCell(const MapCell &copy);
    ~MapCell();
    void operator=(MapCell copy);
    bool isFree();
    bool hasEntities();
    Image *getImage();
    void setImage(Image *_image);
    void addEntity(Entity *entity);
    Entity *removeEntity(Entity *entity);
    std::list<Entity *> getEntities();
};


class Map {
    MapGenerator generator;
    MapCell **cells;
    MapCell emptyCell;
    MapCell wallCell;
    MapCell floorCell;
    MapCell startCell;
    MapCell endCell;
    std::list<Entity *> mobs;
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
