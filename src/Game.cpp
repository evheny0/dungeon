#include "Game.h"

Game::Game() : frame(0)
{
    windowInit();
    modulesInit();
}

void Game::modulesInit()
{
    configManager = new ConfigManager();
    assetManager = new AssetManager();
    Drawable::assetManager = assetManager;
    stateManager = new StateManager();
}

void Game::windowInit()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Dungeon");
    window.clear();
    Drawable::window = &window;
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
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
        input(event);
        update();
        show();
    }
}

bool Game::isRunning()
{
    return stateManager->isRunning();  
    //return window.isOpen();
}

void Game::input(sf::Event &event)
{
    while(window.pollEvent(event)) {
        stateManager->input(event);
    }
}

void Game::update()
{
    stateManager->update();
}

void Game::show()
{
    window.clear(sf::Color(24, 12, 28, 225));
    stateManager->show();
    window.display();
}



void Game::checkFPS()
{
    frame++;
    if (clock.getElapsedTime().asMilliseconds() >= 1000) {
        std::cout << frame << std::endl;
        clock.restart();
        frame = 0;
    }
}


AssetManager* Game::getAssetManager()
{
    return assetManager;
}
