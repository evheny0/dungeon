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

void Map::generate(int seed)
{
    generator.generate();
    generator.show();
}

void Map::render()
{
    int i, j;
    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            switch (generator[i][j]) {
                case FLOOR:
                    background.draw(floor, i * 32, j * 32);
                    break;
                case WALL:
                    break;
            }
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

void Map::reallocValues()
{
    values = new MapCell*[sizeX];
    for (int i = 0; i < sizeX; i++) {
        values[i] = new MapCell[sizeY];
    }
}

void Map::show()
{
    background.show();
}
