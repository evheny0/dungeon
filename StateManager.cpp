#include "StateManager.h"

StateManager::StateManager()
{
    currentState = new Splash(this);
}

StateManager::~StateManager()
{
    
}

IState *StateManager::getState()
{
    return currentState;
}

void StateManager::quit()
{
    currentState = NULL;
}
