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
    IState *currentState;
  public:
    Game();
    ~Game();
    void windowInit();
    bool run();
    void loop();
    bool isRunning();
    void input();
    void update();
    void render();
};


#endif