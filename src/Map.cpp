#include "Map.h"


Map::Map(int x, int y) : background(x * TILE_SIZE, y * TILE_SIZE)
{
    sizeX = x;
    sizeY = y;
    reallocValues();
    clear();
    loadImages();
    render();
}

Map::~Map()
{

}

void Map::loadImages()
{
    floor = Game::assetManager->getImage(floorID);
    wall = Game::assetManager->getImage(wallID);
    wallDown = Game::assetManager->getImage(wallDownID);
    door = Game::assetManager->getImage(doorID);

    border_up = Game::assetManager->getImage(borderUpID);
    border_down = Game::assetManager->getImage(borderDownID);
    border_right = Game::assetManager->getImage(borderRightID);
    border_left = Game::assetManager->getImage(borderLeftID);

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

                    if (generator[i][j - 1] == WALL) {
                        //background.draw(border_up, i * TILE_SIZE, j * TILE_SIZE);
                        background.draw(wall, i * TILE_SIZE, (j - 2) * TILE_SIZE);
                        // need another tileset for walls
                        // drawing walls
                        /*
                        switch (getRandomNumber(0, 3)) {
                        case 0:
                            background.draw(wall, i * TILE_SIZE, (j - 1) * TILE_SIZE);
                            break;
                        case 1:
                            background.draw(wall, i * TILE_SIZE, (j - 1) * TILE_SIZE);
                            background.draw(wall, i * TILE_SIZE, (j - 2) * TILE_SIZE);
                            break;
                        case 2:
                            background.draw(wall, i * TILE_SIZE, (j - 1) * TILE_SIZE);
                            background.draw(wall, i * TILE_SIZE, (j - 2) * TILE_SIZE);
                            background.draw(wall, i * TILE_SIZE, (j - 3) * TILE_SIZE);
                            break;
                        }*/
                    }
                    if (generator[i - 1][j] == WALL) {
                        background.draw(border_left, i * TILE_SIZE, j * TILE_SIZE);
                    }
                    break;
                case WALL:
                    if (generator[i][j - 1] == FLOOR) {
                        background.draw(wallDown, i * TILE_SIZE, j * TILE_SIZE);
                        //background.draw(border_down, i * TILE_SIZE, (j - 1) * TILE_SIZE);
                    }
                    if (generator[i - 1][j] == FLOOR) {
                        background.draw(border_right, (i - 1) * TILE_SIZE, j * TILE_SIZE);
                    }
                    break;
                case START:
                    startX = i;
                    startY = j;
                case END:
                    background.draw(floor, i * TILE_SIZE, j * TILE_SIZE);
                    background.draw(door, i * TILE_SIZE, (j - 2) * TILE_SIZE);
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

bool Map::isIntersects(int x, int y)
{
    if (generator[x][y] == WALL) {  // need to rewrite
        return true;
    } 
    return false;
}
