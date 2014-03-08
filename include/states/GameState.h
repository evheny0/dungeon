#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include <map>
#include "Assets.h"
#include "states/IState.h"
#include "gui/Button.h"
#include "EventHandler.h"
#include "Functor.h"
#include "Image.h"
#include "entity/Player.h"
#include "Map.h"
#include <iostream>

const int MAP_SIZE_X = 100;
const int MAP_SIZE_Y = 100;


class GameState : public IState, public EventHandler {
    Image *floor;
    Player player;
    std::map<int, Entity *> entityMap;
    //std::vector< std::vector<MapCell *> > levelMap;
    Map levelMap;
  public:
    GameState(StateManager *stateManager);
    ~GameState();
    
    void input(sf::Event &event);
    void update();
    void show();
  private:
    void eventClosed();
    void eventKeyPressed(sf::Event::KeyEvent &key);

    void checkPlayerControls();
};





#endif // GAME_STATE_H
