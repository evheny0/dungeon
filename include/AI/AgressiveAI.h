#ifndef AGRESSIVE_AI_H
#define AGRESSIVE_AI_H


#include "AI/BasicAI.h"
#include <cstdlib>
#include "entity/Entity.h"


class AgressiveAI : public BasicAI {
    Entity *entity;
  public:
    AgressiveAI(Entity *_entity);
    ~AgressiveAI();

    void updateState(Map *levelMap);  
};

#include "Map.h"

#endif // AGRESSIVE_AI_H
