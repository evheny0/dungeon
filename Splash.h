#ifndef SPLASH_H
#define SPLASH_H

#include <SFML/Graphics.hpp>
#include "IState.h"
#include "StateManager.h"

class StateManager;


class Splash : public IState {
    StateManager *stateManager;
  public:
    Splash(StateManager *stateManager);
    ~Splash();
    void input(sf::Event &event);
    void update();
    void draw();
};


#endif