#ifndef SKELETON_H
#define SKELETON_H


#include "AI/AgressiveAI.h"
#include "Entity.h"


class Skeleton : public Entity {
    BasicAI *ai; 
  public:
    Skeleton(int x, int y);
    ~Skeleton();

    void act(Map *levelMap);
};


#endif // SKELETON_H
