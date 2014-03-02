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
    // Here is a problem with the images, which are equal to one instance

    startButton.setTextAndImages("Start", Game::assetManager->getImage(buttonID), Game::assetManager->getImage(button_inactiveID));
    settingsButton.setTextAndImages("Settings", Game::assetManager->getImage(buttonID), Game::assetManager->getImage(button_inactiveID));
    quitButton.setTextAndImages("Quit", Game::assetManager->getImage(buttonID), Game::assetManager->getImage(button_inactiveID));

    startButton.setPosition(100, 100);
    settingsButton.setPosition(100, 200);
    quitButton.setPosition(100, 300);
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

void MainMenu::eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton)
{

}

