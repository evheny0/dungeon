#include "EventHandler.h"

void EventHandler::inputEvent(sf::Event &event)
{
    switch (event.type) {
    case sf::Event::KeyPressed:
        eventKeyPressed(event.key);
        break;

    case sf::Event::KeyReleased:
        eventKeyReleased(event.key);
        break;

    case sf::Event::TextEntered:
        eventTextEntered(event.text);
        break;

    case sf::Event::MouseMoved:
        eventMouseMoved(event.mouseMove);
        break;

    case sf::Event::MouseButtonPressed:
        eventMouseButtonPressed(event.mouseButton);
        break;

    case sf::Event::MouseButtonReleased:
        eventMouseButtonReleased(event.mouseButton);
        break;

    case sf::Event::MouseWheelMoved:
        eventMouseWheelMoved(event.mouseWheel);
        break;

    case sf::Event::Closed:
        eventClosed();
        break;
    }
}
