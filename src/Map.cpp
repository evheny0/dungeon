#include "Map.h"


Map::Map(int x, int y) : background(x * TILE_SIZE, y * TILE_SIZE)
{
    sizeX = x;
    sizeY = y;
    reallocValues();
    clear();
    floor = Game::assetManager->getImage(floorID);
    //generate();
    render();
}

Map::~Map()
{

}

void Map::render()
{
    int i, j;
    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            background.draw(floor, i * 32, j * 32);
        }
    }
    background.formImage();
}

MapCell *Map::operator[](int x)
{
    return values[x];
}


void Map::clear()
{
    int i, j;
    for (i = 0; i < sizeX; i++) {
        for (j = 0; j < sizeY; j++) {
            values[i][j] = emptyCell;
        }
    }
}



void Map::show()
{
    background.show();
}



void Map::reallocValues()
{
    values = new MapCell*[sizeX];
    for (int i = 0; i < sizeX; i++) {
        values[i] = new MapCell[sizeY];
    }
}
