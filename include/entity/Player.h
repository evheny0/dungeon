#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "graphic/Animation.h"
#include "entity/Entity.h"


class Player : public Entity {
  public:
    Player();
    ~Player();
    void initAnimation();
    void act(Map *levelMap);
};


#endif // PLAYER_H
