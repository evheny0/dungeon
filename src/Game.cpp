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
    Drawable::window = &window;
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
        while(window.pollEvent(event)) {
            stateManager->input(event);
        }
        update();
        show();
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

void Game::show()
{
    window.clear();
    stateManager->show();
    window.display();
}



AssetManager* Game::getAssetManager()
{
    return assetManager;
}
