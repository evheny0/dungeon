#include "states/GameState.h"

GameState::GameState(StateManager *stateManager) : IState(stateManager),
                                                   levelMap(MAP_SIZE_X, MAP_SIZE_Y)
{
    floor = Game::assetManager->getImage(floorID);
    entityMap[10] = new Entity; 
    levelMap.render();
    player.setPosition(100, 100);
    camera.reset(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    camera.apply();
}

GameState::~GameState()
{
    camera.setDefault();
}



void GameState::input(sf::Event &event)
{
    inputEvent(event);
}

void GameState::update()
{
    checkPlayerControls();
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

void GameState::eventKeyPressed(sf::Event::KeyEvent &key)
{

}


void GameState::checkPlayerControls()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player.moveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.moveRight();
    }
}

void GameState::updateCamera()
{
    camera.setCenter(player.getX(), player.getY());
}
