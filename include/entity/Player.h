#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Assets.h"
#include "Image.h"


class Player {
    Image *image;
  public:
    Player();
    ~Player();

    void setPosition(int x, int y);
    void show();
};


#include "Game.h"

#endif // PLAYER_H
