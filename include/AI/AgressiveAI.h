#ifndef AGRESSIVE_AI_H
#define AGRESSIVE_AI_H

#include <list>
#include <cstdlib>
#include "AI/BasicAI.h"
#include "entity/Entity.h"

const int RANGE = 200;


class AgressiveAI : public BasicAI {
    Entity *entity;
  public:
    AgressiveAI(Entity *_entity);
    ~AgressiveAI();

    void updateState(Map *levelMap);  
    Entity *findEnemy(Map *levelMap);
};

#include "Map.h"

#endif // AGRESSIVE_AI_H
