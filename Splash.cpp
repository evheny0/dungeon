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
    if (event.type == sf::Event::Closed) {
        stateManager->quit();
    }
}

void Splash::update()
{

}

void Splash::draw()
{

}
