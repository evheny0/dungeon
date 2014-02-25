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
    sf::Event event;

    while(isRunning()) {
        window.pollEvent(event);

        currentState = stateManager.getState();
        currentState->input(event);
        update();
        render();
    }
}

bool Game::isRunning()
{
    if(!stateManager.getState()) {
        return false;
    }
    return true;  
    //return window.isOpen();
}

void Game::update()
{
    currentState->update();
}

void Game::render()
{
    window.clear();
    currentState->render();
    window.display();
}
