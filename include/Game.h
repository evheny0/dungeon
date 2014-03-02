#ifndef GAME_H
#define GAME_H

#include "AssetManager.h"
#include "ConfigManager.h"
#include "StateManager.h"
#include "Image.h"

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 540;

class StateManager;


class Game {
  public:
    sf::RenderWindow window;
    static AssetManager *assetManager;

  private:
    ConfigManager *configManager;
    StateManager *stateManager;

  public:
    Game();
    ~Game();
    void modulesInit();
    void windowInit();

    int run();
    void loop();
    bool isRunning();
    void input();
    void update();
    void render();

    AssetManager *getAssetManager();
    void hello();
};


#endif
