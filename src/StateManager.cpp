#include "StateManager.h"

StateManager::StateManager()
{
    currentState = new Splash(this);
}

StateManager::~StateManager()
{
    cleanUpStates();
}

void StateManager::cleanUpStates()
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
