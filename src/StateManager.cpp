#include "StateManager.h"

StateManager::StateManager()
{
    statesStack.push(new Splash(this));
    nextState = statesStack.top();
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
    statesStack.top()->input(event);
}

void StateManager::update()
{
    statesStack.top()->update();
}

void StateManager::render()
{
    statesStack.top()->render();
}



void StateManager::pushState(IState *state)
{
    statesStack.push(state);         // needs rewriting
    nextState = state;               // also need remove pointers
}

void StateManager::popState()
{
    delete nextState;                // 
    statesStack.pop();               // needs rewriting
    nextState = statesStack.top();   //
}

void StateManager::resetState()
{
    nextState = NULL;                //
}

void StateManager::setNextState(IState *state)
{
    nextState = state;               // needs rewriting
}

void StateManager::updateCurrentState()
{
    if (statesStack.top() != nextState) {
        /*
        if (!(statesStack.empty()) && nextState != statesStack.top()) {
            currentState = nextState;
            return;
        }*/
        /*delete */
        delete statesStack.top();    // 
        statesStack.pop();           // needs rewriting
        statesStack.push(nextState); // 
    }
}

void StateManager::cleanUpStates()
{
    //delete currentState;
    //delete states in stack
}
