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
    startButton.setTextAndImages("Start", Game::assetManager->getImage(buttonID), Game::assetManager->getImage(button_inactiveID));
    settingsButton.setTextAndImages("Settings", Game::assetManager->getImage(buttonID), Game::assetManager->getImage(button_inactiveID));
    quitButton.setTextAndImages("Quit", Game::assetManager->getImage(buttonID), Game::assetManager->getImage(button_inactiveID));

    startButton.setPosition(110, 110);
    settingsButton.setPosition(10, 10);
    quitButton.setPosition(50, 150);
}



void MainMenu::input(sf::Event &event)
{
    inputEvent(event);
}

void MainMenu::update() 
{
    //quitButton.setPosition(500, 150);
}

void MainMenu::render()
{
    startButton.render();
    settingsButton.render();
    quitButton.render();
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

