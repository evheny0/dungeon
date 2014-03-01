#ifndef ISTATE_H
#define ISTATE_H

#include <SFML/Graphics.hpp>


class StateManager;


class IState {
  protected:
    StateManager *stateManager;
  public:
    IState(StateManager *stateManager) { this->stateManager = stateManager; }
    
    virtual void input(sf::Event &event) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual IState *nextState() { };
};


#include "StateManager.h"

#endif
