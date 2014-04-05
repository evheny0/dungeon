#ifndef GAME_H
#define GAME_H

#include "AssetManager.h"
#include "ConfigManager.h"
#include "StateManager.h"
#include "CoreTypes.h"
#include "graphic/Drawable.h"


class Game {
    sf::RenderWindow window;
    AssetManager *assetManager;
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
