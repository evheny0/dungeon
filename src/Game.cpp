#include "Game.h"

Game::Game()
{
    windowInit();
    modulesInit();
}

void Game::modulesInit()
{
    configManager = new ConfigManager();
    assetManager = new AssetManager();
    stateManager = new StateManager();
}

void Game::windowInit()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Dungeon");
    Image::window = &window;
    window.setVerticalSyncEnabled(true);
}

Game::~Game()
{
    delete configManager;
    delete assetManager;
    delete stateManager;
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

        stateManager->input(event);
        update();
        render();
    }
}

bool Game::isRunning()
{
    return stateManager->isRunning();  
    //return window.isOpen();
}

void Game::update()
{
    stateManager->update();
}

void Game::render()
{
    window.clear();
    stateManager->render();
    window.display();
}



AssetManager* Game::getAssetManager()
{
    return assetManager;
}
