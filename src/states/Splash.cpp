#include "states/Splash.h"

Splash::Splash(StateManager *stateManager) : IState(stateManager)
{
    splash = new Image(splashID);
}

Splash::~Splash()
{
    delete splash;
}

void Splash::input(sf::Event &event)
{
    inputEvent(event);
}

void Splash::update()
{
    if (timer.getElapsedTime() > sf::milliseconds(300)) {
        stateManager->setNextState(new MainMenu(stateManager));
    }
}

void Splash::show()
{
    splash->setPosition(0, 0);
    splash->show();
}



void Splash::eventClosed()
{
    stateManager->resetState();
}
