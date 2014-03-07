#include "states/Splash.h"

Splash::Splash(StateManager *stateManager) : IState(stateManager)
{
    splash = Game::assetManager->getImage(splashID);
}
#include <iostream>
Splash::~Splash()
{
    std::cout << "Splash destr\n";
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

void Splash::render()
{
    splash->setPosition(0, 0);
    splash->show();
}



void Splash::eventClosed()
{
    stateManager->resetState();
}
