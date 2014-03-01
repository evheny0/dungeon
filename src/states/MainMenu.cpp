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

    startButton.setPosition(50, 50);
    settingsButton.setPosition(50, 80);
    quitButton.setPosition(50, 110);
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

