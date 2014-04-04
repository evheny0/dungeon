#ifndef MAP_GENERATOR_H
#define MAP_GENERATOR_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

/*
    генерируем NUM_OF_ROOMS комнат
    на каждой итерации берем случайную комнату и связываем с новой
*/

const int SIZE_X = 70;
const int SIZE_Y = 70;
const int NUM_OF_ROOMS = 10;
const int MIN_SIZE_OF_ROOM = 10;
const int MAX_SIZE_OF_ROOM = 20;

const char EMPTY = ' ';
const char WALL = '#';
const char FLOOR = '.';
const char CORRIDOR = ':';
const char DOOR = '+';
const char START = 'S';
const char END = 'E';

const char MOB = 'M';


int getRandomNumber(int min, int max);


struct Coord {
    int x, y;

    Coord();
    Coord(int _x, int _y);
    Coord(const Coord &copy);

    void operator+=(int value);
    void setRandom();
    friend Coord operator+(const Coord &coord, const int value);
    friend Coord operator+(const Coord &first, const Coord &second);
};

class Room {            // set inheritance from sf::Rect
    Coord start, end;
    int roomSize;
  public:
    Room();
    Room(Coord _start, Coord _end);
    Room(const Room &copy);
    void generate();
    bool isInField();
    Coord getStart();
    Coord getEnd();
    Coord getRandomCoord();
};

class MapGenerator {
    int seed;
    char **values;
    int mapWorth;
    std::vector<Room> rooms;
    Coord levelStart;
    Coord levelEnd;
  public:
    MapGenerator();
    ~MapGenerator();
    char *operator[](int x);
    void setSeed(int _seed);
    bool isIntersects(Coord start, Coord end);
    void show();
    Room getRandomRoom();
    Room generateNewRoom();
    void setEnd(Room newRoom);
    void setStart(Room room);
    void linkRooms(Room startRoom, Room endRoom);
    void makeHCorridor(int start, int end, int y);
    void makeVCorridor(int start, int end, int x);
    void fillRoom(Room room);
    void fillFloor(Coord start, Coord end);
    void fillOutline(Coord start, Coord end);
    void setMobs(Coord start, Coord end);
    void generate();
};



#endif // MAP_GENERATOR_H
