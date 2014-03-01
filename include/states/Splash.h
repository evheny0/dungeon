#ifndef SPLASH_H
#define SPLASH_H

#include <SFML/Graphics.hpp>
#include "states/IState.h"

#include "EventHandler.h"
#include "Image.h"
#include "Assets.h"

#include "MainMenu.h"


class Splash : public IState, public EventHandler {
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
