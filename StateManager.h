#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <map>
#include "CoreTypes.h"
#include "IState.h"

class StateManager {
    std::map<stateID, IState> states;
    IState *currentState;
  public:
    StateManager();
    ~StateManager();
    IState *getState();
};

#endif