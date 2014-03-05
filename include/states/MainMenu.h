#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <vector>
#include "Assets.h"
#include "states/IState.h"
#include "gui/Button.h"
#include "EventHandler.h"
#include "Functor.h"
#include "states/Settings.h"


class MainMenu : public IState, public EventHandler {
    std::vector<Button *> buttons;
    std::vector<Button *>::iterator it;
  public:
    MainMenu(StateManager *stateManager);
    ~MainMenu();
    void initButtons();
    Button *newButton(std::string str, void(MainMenu::*callback)());
    void input(sf::Event &event);
    void update();
    void render();

    void onExit();
    void onSettings();
    void onStartGame();

  private:
    void eventMouseMoved(sf::Event::MouseMoveEvent &mouseMove);
    void eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton);
    void eventClosed();
};


#endif // MAIN_MENU_H
