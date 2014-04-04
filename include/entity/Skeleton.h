#ifndef SKELETON_H
#define SKELETON_H


#include "AI/AgressiveAI.h"


class Skeleton : public Entity {
    BasicAI *ai; 
  public:
    Skeleton(int x, int y);
    ~Skeleton();

    void act(Map *levelMap);
};


#include "Game.h"

#endif // SKELETON_H
