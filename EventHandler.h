#ifndef I_EVENT_HANDLER_H
#define I_EVENT_HANDLER_H

#include <SFML/Window/Event.hpp>


class EventHandler {
  public:
    void inputEvent(sf::Event &event);
    virtual void eventKeyPressed(sf::Event::KeyEvent &key) {};
    virtual void eventKeyReleased(sf::Event::KeyEvent &key) {};
    virtual void eventTextEntered(sf::Event::TextEvent &text) {};
    virtual void eventMouseMoved(sf::Event::MouseMoveEvent &mouseMove) {};
    virtual void eventMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton) {};
    virtual void eventMouseButtonReleased(sf::Event::MouseButtonEvent &mouseButton) {};
    virtual void eventMouseWheelMoved(sf::Event::MouseWheelEvent &mouseWheel) {};
    virtual void eventClosed() {};
};


#endif