#include "Splash.h"

Splash::Splash(StateManager *stateManager)
{
    this->stateManager = stateManager;
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

void Splash::draw()
{

}

void Splash::eventClosed()
{
    stateManager->quit();
}
