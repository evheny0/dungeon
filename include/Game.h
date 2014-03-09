#ifndef GAME_H
#define GAME_H

#include "AssetManager.h"
#include "ConfigManager.h"
#include "StateManager.h"
#include "graphic/Image.h"
#include "CoreTypes.h"

class StateManager;


class Game {
    sf::RenderWindow window;
  public:
    static AssetManager *assetManager;

  private:
    ConfigManager *configManager;
    StateManager *stateManager;

  private:
    sf::Clock clock;
    sf::Time elapsedTime;
    int frame;

  public:
    Game();
    ~Game();
    void modulesInit();
    void windowInit();

    int run();
    void loop();
    bool isRunning();
    void input(sf::Event &event);
    void update();
    void show();
    void checkFPS();

    AssetManager *getAssetManager();
};


#endif
