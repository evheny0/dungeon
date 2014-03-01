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



void EventHandler::eventMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton)
{
    switch (mouseButton.button) {
    case sf::Mouse::Left:
        eventLeftMouseButtonPressed(mouseButton);
        break;

    case sf::Mouse::Right:
        eventRightMouseButtonPressed(mouseButton);
        break;

    case sf::Mouse::Middle:
        eventMiddleMouseButtonPressed(mouseButton);
        break;
    }
}

void EventHandler::eventMouseButtonReleased(sf::Event::MouseButtonEvent &mouseButton)
{
    switch (mouseButton.button) {
    case sf::Mouse::Left:
        eventLeftMouseButtonReleased(mouseButton);
        break;

    case sf::Mouse::Right:
        eventRightMouseButtonReleased(mouseButton);
        break;

    case sf::Mouse::Middle:
        eventMiddleMouseButtonReleased(mouseButton);
        break;
    }
}

