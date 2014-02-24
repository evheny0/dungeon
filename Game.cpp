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
    while(isRunning()) {
        input();
        update();
        render();
    }
}

bool Game::isRunning()
{
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
