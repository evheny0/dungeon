#include "states/GameState.h"

GameState::GameState(StateManager *stateManager) : IState(stateManager),
                                                   levelMap(MAP_SIZE_X, MAP_SIZE_Y)
{
    levelMap.generate();
    levelMap.render();
    player.setPosition(levelMap.startX * TILE_SIZE, levelMap.startY * TILE_SIZE);
    camera.reset(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

GameState::~GameState()
{
    camera.setDefault();
} 



void GameState::input(sf::Event &event)
{
    inputEvent(event);
    player.input(event);
}

void GameState::update()
{
    player.act(&levelMap);
    levelMap.update();
    updateCamera();
}

void GameState::show()
{
    camera.apply();
    levelMap.show();
    player.show();
}



void GameState::eventClosed()
{
    stateManager->resetState();
}

void GameState::updateCamera()
{
    camera.setCenter(player.getX(), player.getY());
}
