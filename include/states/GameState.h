#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include <map>
#include "Assets.h"
#include "states/IState.h"
#include "gui/Button.h"
#include "EventHandler.h"
#include "Functor.h"
#include "graphic/Image.h"
#include "entity/Player.h"
#include "Map.h"
#include "Camera.h"

const int MAP_SIZE_X = 70;
const int MAP_SIZE_Y = 70;


class GameState : public IState, public EventHandler {
    Image *floor;
    Player player;
    Map levelMap;
    Camera camera;
  public:
    GameState(StateManager *stateManager);
    ~GameState();
    
    void input(sf::Event &event);
    void update();
    void show();
  private:
    void eventClosed();
    void eventKeyPressed(sf::Event::KeyEvent &key);
    void eventKeyReleased(sf::Event::KeyEvent &key);

    void updateCamera();
};


#endif // GAME_STATE_H
