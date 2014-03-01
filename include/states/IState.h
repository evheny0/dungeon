#ifndef ISTATE_H
#define ISTATE_H

#include <SFML/Graphics.hpp>


class IState {
  public:
    virtual void input(sf::Event &event) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual IState *nextState() { };
};

#endif
