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
    floor = new Image(floorID);
    wall = new Image(wallID);
    wallDown = new Image(wallDownID);
    door = new Image(doorID);

    border_up = new Image(borderUpID);
    border_down = new Image(borderDownID);
    border_right = new Image(borderRightID);
    border_left = new Image(borderLeftID);
}

void Map::generate(int seed)
{
    generator.generate();
    generator.show();
    generateMobs();
}

void Map::generateMobs()
{
    int i, j, x, y;
    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            if (generator[i][j] == MOB) {
                x = getRandomNumber(i * TILE_SIZE, (i + 1) * TILE_SIZE - 1);
                y = getRandomNumber(j * TILE_SIZE, (j + 1) * TILE_SIZE - 1);
                mobs.push_back(new Skeleton(x, y));
                generator[i][j] = FLOOR;
            }
        }
    }
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
                    background.draw(floor, i * TILE_SIZE, j * TILE_SIZE);
                    background.draw(door, i * TILE_SIZE, (j - 2) * TILE_SIZE);
                    break;
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

void Map::update()
{
    std::list<Entity *>::iterator it;
    for (it = mobs.begin(); it != mobs.end(); it++) {
        (*it)->act(this);
    }
}

void Map::show()
{
    background.show();
    showMobs();
}

void Map::showMobs()
{
    std::list<Entity *>::iterator it;
    for (it = mobs.begin(); it != mobs.end(); it++) {
        (*it)->show();
    }
}

bool Map::isIntersects(int x, int y)
{
    if (generator[x][y] == WALL) {  // need to rewrite. Calling isPassable() method implementation
        return true;
    } 
    return false;
}
