#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Assets.h"
#include "Image.h"
#include "Entity.h"


class Player {
    Image *image;
    int velocity;
    int x, y;
  public:
    Player();
    ~Player();
    int getX();
    int getY();
    void setPosition(int x, int y);

    void setVelocity(int vel);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void show();
};


#include "Game.h"

#endif // PLAYER_H
