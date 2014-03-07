#include "states/GameState.h"

GameState::GameState(StateManager *stateManager) : IState(stateManager)
{
    floor = Game::assetManager->getImage(floorID);

}

GameState::~GameState()
{

}



void GameState::input(sf::Event &event)
{
    inputEvent(event);
}

void GameState::update()
{

}

void GameState::render()
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            floor->setPosition(i * 32, j * 32);
            floor->show();
        }
    }
    player.setPosition(10, 10);
    player.show();
}



void GameState::eventClosed()
{
    stateManager->resetState();
}




