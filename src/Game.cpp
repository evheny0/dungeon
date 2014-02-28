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

int Game::run()
{
    loop();
    return 0;
}

void Game::loop()
{
    sf::Event event;

    while(isRunning()) {
        window.pollEvent(event);

        stateManager.input(event);
        update();
        render();
    }
}

bool Game::isRunning()
{
    return stateManager.isRunning();  
    //return window.isOpen();
}

void Game::update()
{
    stateManager.update();
}

void Game::render()
{
    window.clear();
    stateManager.render();
    window.display();
}
