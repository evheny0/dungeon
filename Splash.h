#ifndef SPLASH_H
#define SPLASH_H

#include <SFML/Graphics.hpp>
#include "IState.h"
#include "StateManager.h"
#include "EventHandler.h"

class StateManager;


class Splash : public IState, public EventHandler {
    StateManager *stateManager;
  public:
    Splash(StateManager *stateManager);
    ~Splash();
    void input(sf::Event &event);
    void update();
    void draw();
    void eventClosed();
};


#endif