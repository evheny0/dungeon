#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <list>
#include <cmath>
#include "graphic/Image.h"
#include "graphic/Tileset.h"
#include "CoreTypes.h"
#include "map_generator/MapGenerator.h"

class Entity;


class MapCell {
    std::list<Entity *> entities;
    bool isPassable;
    Image *image;
    int x, y;
  public:
    MapCell(bool _isPassable = false, int x = -1, int y = -1);
    //MapCell(const MapCell &copy);
    ~MapCell();
    //void operator=(MapCell copy);
    void update(MapCell templateCell);
    bool isFree();
    bool hasEntities();
    Image *getImage();
    void setCoord(int _x, int _y);
    int getX();
    int getY();
    void setImage(Image *_image);
    void addEntity(Entity *entity);
    Entity *removeEntity(Entity *entity);
    std::list<Entity *> getEntities();
    Entity *getEnemy(Entity *enemy);
    float getDistance(MapCell destination);
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
