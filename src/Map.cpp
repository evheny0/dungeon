#include "Map.h"


Map::Map(int x, int y) : background(x * TILE_SIZE, y * TILE_SIZE)
{
    sizeX = x;
    sizeY = y;
    reallocValues();
    clear();
    floor = Game::assetManager->getImage(floorID);
    wall = Game::assetManager->getImage(wallID);
    wallDown = Game::assetManager->getImage(wallDownID);
    wallSide = Game::assetManager->getImage(wallSideID);
    door = Game::assetManager->getImage(doorID);
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
    background.clear(sf::Color(8, 8, 28, 225));
    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            switch (generator[i][j]) {
                case FLOOR:
                case CORRIDOR:
                    background.draw(floor, i * TILE_SIZE, j * TILE_SIZE);
                    break;
                case WALL:
                    if (generator[i][j - 1] == FLOOR) {
                        background.draw(wallDown, i * TILE_SIZE, j * TILE_SIZE);
                    }
                    break;
                case DOOR:
                    background.draw(floor, i * TILE_SIZE, j * TILE_SIZE);
                case START:
                    startX = i;
                    startY = j;
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

bool Map::isIntersects(int x, int y)
{
    if (generator[x][y] == WALL) {  // need to rewrite
        return true;
    } return false;
}
