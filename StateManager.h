#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <map>
#include "CoreTypes.h"
#include "IState.h"
#include "Splash.h"

class StateManager {
    std::map<stateID, IState> states;
    IState *currentState;
  public:
    StateManager();
    ~StateManager();
    IState *getState();
    void quit();
};

#endif