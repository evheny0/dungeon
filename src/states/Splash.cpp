#include "states/Splash.h"

Splash::Splash(StateManager *stateManager)
{
    this->stateManager = stateManager;
    splash = Game::assetManager->getImage(splashID);
}

Splash::~Splash()
{

}

void Splash::input(sf::Event &event)
{
    inputEvent(event);
}

void Splash::update()
{

}

void Splash::render()
{
    splash->setPosition(0, 0);
    splash->show();
}

void Splash::eventClosed()
{
    stateManager->resetState();
}
