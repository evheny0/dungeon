#include "AI/AgressiveAI.h"

AgressiveAI::AgressiveAI(Entity *_entity)
{
    entity = _entity;
}

AgressiveAI::~AgressiveAI()
{
    
}
#include <iostream>
void AgressiveAI::updateState(Map *levelMap)
{
    entity->stop();
    (*levelMap)[entity->getX() / TILE_SIZE][entity->getY() / TILE_SIZE].removeEntity(entity);
    Entity *enemy = findEnemy(levelMap);
    if (enemy) {
        entity->setDestination(enemy->getX(), enemy->getY());
    }

    entity->move();
    (*levelMap)[entity->getX() / TILE_SIZE][entity->getY() / TILE_SIZE].addEntity(entity);
}

// FBS
Entity *AgressiveAI::findEnemy(Map *levelMap)
{
    int x = entity->getX() / TILE_SIZE, y = entity->getY() / TILE_SIZE, i, j;
    std::list<MapCell> cells;
    std::map<MapCell *, bool> visited;
    MapCell current, start = (*levelMap)[x][y];
    Entity *returnValue;
    cells.push_back(start);
    visited[&start] = true;

    while(!cells.empty()) {
        current = cells.back();
        cells.pop_back();

        returnValue = current.getEnemy(entity);
        if (returnValue) {
            return returnValue;
        }

        for (i = current.getX() - 1; i < current.getX() + 2; i++) {
            for (j = current.getY() - 1; j < current.getY() + 2; j++) {
                if ((*levelMap)[i][j].isFree() && 
                                !visited[&(*levelMap)[i][j]] &&
                                ((*levelMap)[i][j].getDistance(start) * TILE_SIZE) <= RANGE) {
                    cells.push_back((*levelMap)[i][j]);
                    visited[&(*levelMap)[i][j]] = true;

                }
            }
        }
    }
    return NULL;
}
