#include "Game.h"

Game::Game()
{
    windowInit();
}

void Game::windowInit()
{
    window.create(sf::VideoMode(800, 600), "Dungeon");
    Image::window = &window;
    window.setVerticalSyncEnabled(true);
}

Game::~Game()
{

}

bool Game::run()
{
    loop();
    return 0;
}

void Game::loop()
{
    IState *currentState;
    while(isRunning()) {
        currentState = stateManager.getState();
        currentState->input();
        currentState->update();
        currentState->render();
    }
}

bool Game::isRunning()
{
    /*
    if(!stateManager.getState()) {
        return false;
    }
    return true;  
    */
    return window.isOpen();
}

void Game::input()
{

}

void Game::update()
{

}

void Game::render()
{
    window.clear();
    window.display();
}
