#include "states/GameState.h"

GameState::GameState(StateManager *stateManager) : IState(stateManager),
                                                   levelMap(MAP_SIZE_X, MAP_SIZE_Y)
{
    floor = Game::assetManager->getImage(floorID);
    entityMap[10] = new Entity; 
    levelMap.generate();
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
    player.move();
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
    switch (key.code) {
    case sf::Keyboard::W:
        player.runUp();
        break;
    case sf::Keyboard::A:
        player.runLeft();
        break;
    case sf::Keyboard::S:
        player.runDown();
        break;
    case sf::Keyboard::D:
        player.runRight();
        break;
    }
}

void GameState::eventKeyReleased(sf::Event::KeyEvent &key)
{
    switch (key.code) {
    case sf::Keyboard::W:
        player.stopUp();
        break;
    case sf::Keyboard::A:
        player.stopLeft();
        break;
    case sf::Keyboard::S:
        player.stopDown();
        break;
    case sf::Keyboard::D:
        player.stopRight();
        break;
    }

}



void GameState::updateCamera()
{
    camera.setCenter(player.getX(), player.getY());
}
