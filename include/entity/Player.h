#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Assets.h"
#include "graphic/Image.h"
#include "Entity.h"


class Player {
    Image *image;
    int velocity;
    int x, y;   // coords
    int dx, dy; // offset for move
  public:
    Player();
    ~Player();
    int getX();
    int getY();
    void setPosition(int x, int y);

    void setVelocity(int vel);
    void stop();
    void runUp();
    void runDown();
    void runRight();
    void runLeft();
    void stopUp();
    void stopDown();
    void stopRight();
    void stopLeft();
    void move();

    void show();
};


#include "Game.h"

#endif // PLAYER_H
