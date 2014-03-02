#include "states/MainMenu.h"

MainMenu::MainMenu(StateManager *stateManager) : IState(stateManager)
{
    initButtons();
}

MainMenu::~MainMenu()
{

}

void MainMenu::initButtons()
{
    buttons.push_back(newButton("Start"));
    buttons.push_back(newButton("Settings"));
    buttons.push_back(newButton("Quit"));

    buttons[0]->setPosition(100, 100);
    buttons[1]->setPosition(100, 200);
    buttons[2]->setPosition(100, 300);
}

Button *MainMenu::newButton(std::string text)
{
    return new Button(text, Game::assetManager->getImage(buttonID), Game::assetManager->getImage(button_inactiveID));
}



void MainMenu::input(sf::Event &event)
{
    inputEvent(event);
}

void MainMenu::update() 
{

}

void MainMenu::render()
{
    for (std::vector<Button *>::iterator i = buttons.begin(); i != buttons.end(); ++i) {
        (*i)->render();
    }
}



void MainMenu::eventMouseMoved(sf::Event::MouseMoveEvent &mouseMove)
{

}

void MainMenu::eventClosed()
{
    stateManager->resetState();
}

void MainMenu::eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton)
{

}
