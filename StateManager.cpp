#include "StateManager.h"

StateManager::StateManager()
{
    currentState = NULL;
}

StateManager::~StateManager()
{
    
}

IState *StateManager::getState()
{
    return currentState;
}
