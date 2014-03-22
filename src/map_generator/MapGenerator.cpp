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
    if (end.x >= SIZE_X || end.y >= SIZE_Y) {
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

Coord Room::getRandomCoord()
{
    Coord returnValue;
    returnValue.x = getRandomNumber(start.x + 2, end.x - 2);
    returnValue.y = getRandomNumber(start.y + 2, end.y - 2);
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

void MapGenerator::setEnd(Room room)
{
    levelEnd = room.getStart() + 1;
    values[++levelEnd.x][levelEnd.y] = END;
}

void MapGenerator::setStart(Room room)
{
    levelStart = room.getStart() + 1;
    values[++levelStart.x][levelStart.y] = START;
}

void MapGenerator::linkRooms(Room startRoom, Room endRoom)
{
    int xPos;
    Coord start = startRoom.getRandomCoord();
    Coord end = endRoom.getRandomCoord();

    if (start.x > end.x) {
        std::swap(start, end);
    }
    makeHCorridor(start.x, end.x, start.y);

    xPos = end.x - 1;
    if (start.y > end.y) {
        std::swap(start, end);
    }
    makeVCorridor(start.y - 1, end.y + 1, xPos);
} 

void MapGenerator::makeHCorridor(int start, int end, int y)
{
    for (int i = start; i <= end; i++) {
        (values[i][y - 2] == EMPTY) ? (values[i][y - 2] = WALL) : 0;
        values[i][y - 1] = FLOOR;
        values[i][y] = FLOOR;
        values[i][y + 1] = FLOOR; 
        (values[i][y + 2] == EMPTY) ? (values[i][y + 2] = WALL) : 0;
    }
}

void MapGenerator::makeVCorridor(int start, int end, int x)
{
    for (int i = start; i <= end; i++) {
        (values[x - 2][i] == EMPTY) ? (values[x - 2][i] = WALL) : 0;
        values[x - 1][i] = FLOOR;
        values[x][i] = FLOOR;
        values[x + 1][i] = FLOOR;
        (values[x + 2][i] == EMPTY) ? (values[x + 2][i] = WALL) : 0;
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
    generateNewRoom();
    for (int i = 0; i < NUM_OF_ROOMS; i++) {
        newRoom = generateNewRoom();
        linkRooms(newRoom, getRandomRoom());
    }
    setEnd(newRoom);
    setStart(getRandomRoom());
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
