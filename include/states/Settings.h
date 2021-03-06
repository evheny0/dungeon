#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>
#include <string>
#include "Assets.h"
#include "states/IState.h"
#include "gui/Button.h"
#include "EventHandler.h"
#include "Functor.h"


class Settings : public IState, public EventHandler {
    Button *backButton;
  public:
    Settings(StateManager *stateManager);
    ~Settings();

    void input(sf::Event &event);
    void update();
    void show();

    void onBackButton();

    void eventClosed();
    void eventMouseMoved(sf::Event::MouseMoveEvent &mouseMove);
    void eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton);
};


#endif // SETTINGS_H
