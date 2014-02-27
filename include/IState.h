#ifndef ISTATE_H
#define ISTATE_H

#include <SFML/Graphics.hpp>


class IState {
  public:
    virtual void input(sf::Event &event) { };
    virtual void update() { };
    virtual void render() { };
};

#endif
