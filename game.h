#ifndef GAME_H
#define GAME_H

#include "graphics.h"

class Game {
    sf::RenderWindow window;
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