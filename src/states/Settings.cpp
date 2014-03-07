#include "states/Settings.h"

Settings::Settings(StateManager *stateManager) : IState(stateManager)
{
    backButton = new Button(new Functor<Settings>(this, &Settings::onBackButton));
    backButton->setImages(Game::assetManager->getImage(buttonID), Game::assetManager->getImage(button_inactiveID));
    backButton->setText(Game::assetManager->getText(digiffitiID));
    //backButton->setString("START");
    backButton->setPosition(300, 100);
}

Settings::~Settings()
{

}



void Settings::input(sf::Event &event)
{
    inputEvent(event);
}

void Settings::update()
{

}

void Settings::render()
{
    backButton->render();
}



void Settings::onBackButton()
{
    stateManager->popState();
}



void Settings::eventClosed()
{
    stateManager->resetState();
}

void Settings::eventMouseMoved(sf::Event::MouseMoveEvent &mouseMove)
{
    backButton->mouseMoved(mouseMove.x, mouseMove.y);
}

void Settings::eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton)
{
    backButton->click(mouseButton.x, mouseButton.y);
}


