#include "Map.h"


MapCell::MapCell(bool _isPassable, int _x, int _y)
{
    image = NULL;
    isPassable = _isPassable;
    x = _x;
    y = _y;
}
/*
MapCell::MapCell(const MapCell &copy)
{
    isPassable = copy.isPassable;
    entities = copy.entities;
}*/

MapCell::~MapCell() 
{

}
/*
void MapCell::operator=(MapCell copy)
{
    isPassable = copy.isPassable;
    if (x == -1) {
        x = copy.x;
        y = copy.y;
        entities = copy.entities;
    }
}
*/
void MapCell::update(MapCell templateCell)
{
    isPassable = templateCell.isPassable;
}
    
bool MapCell::isFree()
{
    if (isPassable) {
        return true;
    }
    return false;
}

bool MapCell::hasEntities()
{
    if (entities.empty()) {
        return false;
    }
    return true;
}

void MapCell::setCoord(int _x, int _y)
{
    x = _x;
    y = _y;
}

int MapCell::getX()
{
    return x;
}

int MapCell::getY()
{
    return y;
}

Image *MapCell::getImage()   // no need
{
    return image;
}

void MapCell::setImage(Image *_image)    // no need
{
    image = _image;
}

void MapCell::addEntity(Entity *entity)
{
    entities.push_back(entity);
}

Entity *MapCell::removeEntity(Entity *entity)
{
    entities.remove(entity);
}

std::list<Entity *> MapCell::getEntities()
{
    return entities;
}

Entity *MapCell::getEnemy(Entity *enemy)
{
    std::list<Entity *>::iterator it;
    for (it = entities.begin(); it != entities.end(); it++) {
        if (enemy->isEnemy(*it)) {
            return *it;
        }
    }
    return NULL;
}

float MapCell::getDistance(MapCell destination)
{
    int dx = abs(x - destination.x);
    int dy = abs(y - destination.y);
    float returnValue = sqrt((float) pow(dx, 2) + (float) pow(dy, 2));
    return returnValue;
}



Map::Map(int x, int y) : background(x * TILE_SIZE, y * TILE_SIZE),
                        emptyCell(false),
                        wallCell(false),
                        floorCell(true),
                        startCell(true),
                        endCell(true)
{
    sizeX = x;
    sizeY = y;
    loadImages();
    reallocValues();
    clear();
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
    Entity *entity;
    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            if (generator[i][j] == MOB) {
                x = getRandomNumber(i * TILE_SIZE, (i + 1) * TILE_SIZE - 1);
                y = getRandomNumber(j * TILE_SIZE, (j + 1) * TILE_SIZE - 1);
                entity = new Skeleton(x, y);
                mobs.push_back(entity);
                cells[i][j].addEntity(entity);
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
                    cells[i][j].update(floorCell);

                    if (generator[i][j - 1] == WALL) {
                        //background.draw(border_up, i * TILE_SIZE, j * TILE_SIZE);
                        background.draw(wall, i * TILE_SIZE, (j - 2) * TILE_SIZE);
                    }
                    if (generator[i - 1][j] == WALL) {
                        background.draw(border_left, i * TILE_SIZE, j * TILE_SIZE);
                    }
                    break;
                case WALL:
                    cells[i][j].update(wallCell);
                    if (generator[i][j - 1] == FLOOR) {
                        background.draw(wallDown, i * TILE_SIZE, j * TILE_SIZE);
                        //background.draw(border_down, i * TILE_SIZE, (j - 1) * TILE_SIZE);
                    }
                    if (generator[i - 1][j] == FLOOR) {
                        background.draw(border_right, (i - 1) * TILE_SIZE, j * TILE_SIZE);
                    }
                    break;
                case START:
                    cells[i][j].update(startCell);
                    startX = i;
                    startY = j;
                    background.draw(floor, i * TILE_SIZE, j * TILE_SIZE);
                    background.draw(door, i * TILE_SIZE, (j - 2) * TILE_SIZE);
                    break;
                case END:
                    cells[i][j].update(endCell);
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
    return cells[x];
}

void Map::clear()
{
    int i, j;
    for (i = 0; i < sizeX; i++) {
        for (j = 0; j < sizeY; j++) {
            cells[i][j] = emptyCell;
            cells[i][j].setCoord(i, j);
        }
    }
}

void Map::reallocValues()
{
    cells = new MapCell*[sizeX];
    for (int i = 0; i < sizeX; i++) {
        cells[i] = new MapCell[sizeY];
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
    if (cells[x][y].isFree()) {
        return false;
    } 
    return true;
}
