#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include "Assets.h"
#include "states/IState.h"
#include "gui/Button.h"
#include "EventHandler.h"
#include "Functor.h"
#include "Image.h"
#include "entity/Player.h"


class GameState : public IState, public EventHandler {
    Image *floor;
    Player player;
  public:
    GameState(StateManager *stateManager);
    ~GameState();
    
    void input(sf::Event &event);
    void update();
    void render();
  private:
    void eventClosed();
};





#endif // GAME_STATE_H
