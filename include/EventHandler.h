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
    virtual void eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton) {};
    virtual void eventRightMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton) {};
    virtual void eventMiddleMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton) {};
    virtual void eventLeftMouseButtonReleased(sf::Event::MouseButtonEvent &mouseButton) {};
    virtual void eventRightMouseButtonReleased(sf::Event::MouseButtonEvent &mouseButton) {};
    virtual void eventMiddleMouseButtonReleased(sf::Event::MouseButtonEvent &mouseButton) {};
    virtual void eventMouseWheelMoved(sf::Event::MouseWheelEvent &mouseWheel) {};
    virtual void eventClosed() {};

  private:
    void eventMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton);
    void eventMouseButtonReleased(sf::Event::MouseButtonEvent &mouseButton);
};


#endif
