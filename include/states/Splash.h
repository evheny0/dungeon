#ifndef SPLASH_H
#define SPLASH_H

#include <SFML/Graphics.hpp>
#include "states/IState.h"
#include "StateManager.h"
#include "EventHandler.h"
#include "Graphics.h"
#include "Assets.h"

class StateManager;


class Splash : public IState, public EventHandler {
    StateManager *stateManager;
    Image *splash;
  public:
    Splash(StateManager *stateManager);
    ~Splash();
    void input(sf::Event &event);
    void update();
    void render();
    void eventClosed();
};


#endif
