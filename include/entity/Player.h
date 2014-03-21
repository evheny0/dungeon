#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Assets.h"
#include "graphic/Image.h"
#include "graphic/Animation.h"
#include "Entity.h"


class Player {
    Image *stayRight;
    Image *stayLeft;
    Animation *moveRightAnimation;
    Animation *moveLeftAnimation;
    Image *currentImage;
    int velocity;
    int x, y;     // coords
    int dx, dy;   // offset for move
  public:
    Player();
    ~Player();
    void initAnimation();
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
    void rollback();

    void show();
};


#include "Game.h"

#endif // PLAYER_H
