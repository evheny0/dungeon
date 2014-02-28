#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <iostream>
#include <stack>
#include "CoreTypes.h"
#include "IState.h"
#include "Splash.h"

class StateManager {
    std::stack<IState *> statesStack;
    IState *currentState;
    IState *nextState;
  public:
    StateManager();
    ~StateManager();
    bool isRunning();
    void input(sf::Event &event);
    void update();
    void render();
    void pushState(IState *state);
    void popState();
    void resetState();
  private:
    void cleanUpStates();
    void updateCurrentState();
};

#endif
