#include "map_generator/MapGenerator.h"

int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min);
}


Coord::Coord() : x(0), y(0)
{ 

}

Coord::Coord(int _x, int _y) : x(_x), y(_y)
{

}

Coord::Coord(const Coord &copy)
{
    x = copy.x;
    y = copy.y;
}

void Coord::operator+=(int value) 
{
    x += value;
    y += value;
}

void Coord::setRandom()
{
    x = getRandomNumber(3, SIZE_X - MIN_SIZE_OF_ROOM); // to not get out of range
    y = getRandomNumber(3, SIZE_Y - MIN_SIZE_OF_ROOM); //
}

Coord operator+(const Coord &coord, const int value)
{
    Coord returnValue;
    returnValue.x = coord.x + value;
    returnValue.y = coord.y + value;
    return returnValue;
}

Coord operator+(const Coord &first, const Coord &second)
{
    Coord returnValue;
    returnValue.x = first.x + second.x;
    returnValue.y = first.y + second.y;
    return returnValue;
}





Room::Room()
{

}

Room::Room(Coord _start, Coord _end) : start(_start), end(_end)
{

}

Room::Room(const Room &copy)
{
    start = copy.start;
    end = copy.end;
}

void Room::generate()
{
    do {
        start.setRandom();
        end = start;
        roomSize = getRandomNumber(MIN_SIZE_OF_ROOM, MAX_SIZE_OF_ROOM);
        end += roomSize;
    } while(!isInField());
}

bool Room::isInField()
{
    if (end.x > SIZE_X || end.y > SIZE_Y) {
        return false;
    }
    return true;
}

Coord Room::getStart()
{
    return start;
}

Coord Room::getEnd()
{
    return end;
}

Coord Room::getRandomDoor()
{
    Coord returnValue;
    Coord offset;
    returnValue.x = getRandomNumber(start.x, end.x);
    returnValue.y = getRandomNumber(start.y, end.y);
    if (getRandomNumber(0, 1)) {       // detect, at which wall door will be
        if (getRandomNumber(0, 1)) {
            returnValue.x = start.x;
            //offset.x = -1;
        } else {
            returnValue.x = end.x;
            //offset.x = 1;
        }
    } else {
        if (getRandomNumber(0, 1)) {
            returnValue.y = start.y;
            //offset.y = -1;
        } else {
            returnValue.y = end.y;
            //offset.y = 1;
        }
    }
    //values[returnValue.x][returnValue.y] = DOOR;
    return returnValue/* + offset*/;
}

Coord Room::getRandomCoord()
{
    Coord returnValue;
    returnValue.x = getRandomNumber(start.x + 1, end.x - 1);
    returnValue.y = getRandomNumber(start.y + 1, end.y - 1);
    return returnValue;
}






MapGenerator::MapGenerator()
{
    int i, j;
    values = new char*[SIZE_X];

    for (i = 0; i < SIZE_X; i++) {
        values[i] = new char[SIZE_Y];
        for (j = 0; j < SIZE_Y; j++) {
            values[i][j] = EMPTY;
        }
    }
    seed = time(NULL);
    srand(seed);
}

MapGenerator::~MapGenerator()
{

}

char *MapGenerator::operator[](int x)
{
    return values[x];
}

void MapGenerator::setSeed(int _seed)
{
    seed = _seed;
    srand(seed);
} 

Room MapGenerator::getRandomRoom()
{
    return rooms[getRandomNumber(0, rooms.size() - 1)];
}

bool MapGenerator::isIntersects(Coord start, Coord end)
{
    int i, j;
    for (i = start.x; i < end.x; i++) { 
        for (j = start.y; j < end.y; j++) {
            if (values[i][j] != EMPTY) { 
                return true;
            }
        }
    } 
    return false;
}

Room MapGenerator::generateNewRoom()
{
    Room room;
    do {
        room.generate();
    } while (isIntersects(room.getStart(), room.getEnd()));
    rooms.push_back(room);
    fillRoom(room);
    return room;
}

void MapGenerator::generateStartRoom()
{
    generateNewRoom();
    levelStart = rooms.front().getStart() + 1;
    values[levelStart.x][levelStart.y] = START;
}

void MapGenerator::setEnd(Room newRoom)
{
    levelEnd = newRoom.getStart() + 1;
    values[levelEnd.x][levelEnd.y] = END;
}

void MapGenerator::linkRooms(Room startRoom, Room endRoom)
{
    int i, j, startY;
    //Coord start = startRoom.getRandomDoor();
    //Coord end = endRoom.getRandomDoor();
    Coord start = startRoom.getRandomCoord();
    Coord end = endRoom.getRandomCoord();
    if (start.x > end.x) {
        std::swap(start, end);
    }
    for (i = start.x + 1; i <= end.x; i++) {
        values[i][start.y] = FLOOR;
        values[i][start.y - 1] = FLOOR;
        values[i][start.y + 1] = FLOOR;
        (values[i][start.y + 2] == EMPTY) ? (values[i][start.y + 2] = WALL) : 0;
        (values[i][start.y - 2] == EMPTY) ? (values[i][start.y - 2] = WALL) : 0;
    }

    if (start.y > end.y) {
        std::swap(start, end);
    }
    i--;
    for (j = start.y; j <= end.y; j++) {
        values[i][j] = FLOOR;
        values[i + 1][j] = FLOOR;
        values[i - 1][j] = FLOOR;
        (values[i + 2][j] == EMPTY) ? (values[i + 2][j] = WALL) : 0;
        (values[i - 2][j] == EMPTY) ? (values[i - 2][j] = WALL) : 0;
    }
} 

//void MapGenerator::makeVCorridor

bool MapGenerator::findPath(Coord start, Coord end)  //not start but current
{
    if (values[start.x][start.y] == DOOR) {
        return true;
    }
    if (values[start.x][start.y] != EMPTY) {
        return false;
    }
    if (start.x < end.x) {
        start.x++;

        findPath(start, end);
    } else if (start.x > end.x) {
        start.x--;
    } else {
        start.y--;
    }
}

void MapGenerator::fillRoom(Room room)
{
    fillFloor(room.getStart(), room.getEnd());
    fillOutline(room.getStart(), room.getEnd());
}

void MapGenerator::fillFloor(Coord start, Coord end)
{
    int i, j;
    for (i = start.x; i < end.x; i++) {
        for (j = start.y; j < end.y; j++) {
            values[i][j] = FLOOR;
        }
    }
}

void MapGenerator::fillOutline(Coord start, Coord end)
{
    int i;
    for (i = start.x; i <= end.x; i++) {
        values[i][start.y] = WALL;
        values[i][end.y] = WALL;
    }
    for (i = start.y; i <= end.y; i++) {
        values[start.x][i] = WALL;
        values[end.x][i] = WALL;
    }
}

void MapGenerator::generate()
{
    Room newRoom;
    generateStartRoom();
    for (int i = 0; i < NUM_OF_ROOMS; i++) {
        newRoom = generateNewRoom();
        linkRooms(newRoom, getRandomRoom());
    }
    setEnd(newRoom);
    ///////
    values[levelStart.x][levelStart.y] = START;
    ///////
}

void MapGenerator::show()
{
    int i, j;
    std::cout << "SEED: " << seed << std::endl;
    for (i = 0; i < SIZE_Y; i++) {
        for (j = 0; j < SIZE_X; j++) {
            std::cout << values[j][i];
        }
        std::cout << std::endl;
    }
}
