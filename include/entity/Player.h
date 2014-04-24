#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "graphic/Animation.h"
#include "entity/Entity.h"


class Player : public Entity, public EventHandler {
  public:
    Player();
    ~Player();
    void initAnimation();
    void input(sf::Event &event);
    void eventKeyPressed(sf::Event::KeyEvent &key);
    void eventKeyReleased(sf::Event::KeyEvent &key);
    void eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton);
    void act(Map *levelMap);
};


#endif // PLAYER_H
