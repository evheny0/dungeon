#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "graphic/Animation.h"
#include "entity/Entity.h"


class Player : public Entity {
    Image *stayRight;
    Image *stayLeft;
    Animation *moveRightAnimation;
    Animation *moveLeftAnimation;
  public:
    Player();
    ~Player();
    void initAnimation();

    void runUp();
    void runDown();
    void runRight();
    void runLeft();
    void stopUp();
    void stopDown();
    void stopRight();
    void stopLeft();
};


#include "Game.h"

#endif // PLAYER_H
