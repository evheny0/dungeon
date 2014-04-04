#include "AI/AgressiveAI.h"

AgressiveAI::AgressiveAI(Entity *_entity)
{
    entity = _entity;
}

AgressiveAI::~AgressiveAI()
{
    
}

void AgressiveAI::updateState(Map *levelMap)
{
    do {
        entity->stop();
        switch (rand() % 4) {
        case 0:
            entity->runUp();
            break;
        case 1:
            entity->runDown();
            break;
        case 2:
            entity->runLeft();
            break;
        case 3:
            entity->runRight();
            break;
        }
        entity->move();
        if (levelMap->isIntersects(entity->getX() / TILE_SIZE, entity->getY() / TILE_SIZE)) {
            entity->rollback();
            continue;
        }
    } while (false);
}
