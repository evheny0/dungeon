#ifndef GAME_H
#define GAME_H

#include "AssetManager.h"
#include "ConfigManager.h"
#include "StateManager.h"
#include "Graphics.h"

class Game {
    sf::RenderWindow window;
    AssetManager assetManager;
    ConfigManager configManager;
    StateManager stateManager;
  public:
    Game();
    ~Game();
    void windowInit();
    int run();
    void loop();
    bool isRunning();
    void input();
    void update();
    void render();
};

extern Game game;


#endif