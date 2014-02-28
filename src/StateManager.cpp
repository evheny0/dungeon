#include "StateManager.h"

StateManager::StateManager()
{
    currentState = new Splash(this);
    nextState = currentState;
}

StateManager::~StateManager()
{
    cleanUpStates();
}

bool StateManager::isRunning()
{
    if (!nextState) {
        return false;
    }
    return true;
}



void StateManager::input(sf::Event &event)
{
    updateCurrentState();
    currentState->input(event);
}

void StateManager::update()
{
    currentState->update();
}

void StateManager::render()
{
    currentState->render();
}



void StateManager::pushState(IState *state)
{
    statesStack.push(currentState);
    nextState = state;
}

void StateManager::popState()
{
    nextState = statesStack.top();
    statesStack.pop();
}

void StateManager::resetState()
{
    nextState = NULL;
}



void StateManager::updateCurrentState()
{
    if (currentState != nextState) {
        delete currentState;
        currentState = nextState;
    }
}

void StateManager::cleanUpStates()
{
    delete currentState;
    //delete states in stack
}
