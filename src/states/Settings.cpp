#include "states/Settings.h"

Settings::Settings(StateManager *stateManager) : IState(stateManager)
{
    std::string str = "BACK";
    backButton = new Button(new Functor<Settings>(this, &Settings::onBackButton));
    backButton->setImages(new Image(buttonID), new Image(button_inactiveID));
    backButton->setText(new Text(digiffitiID));
    backButton->setString(str);
    backButton->setPosition(300, 100);
}

Settings::~Settings()
{

}



void Settings::input(sf::Event &event)
{
    inputEvent(event);
}

void Settings::update()
{

}

void Settings::show()
{
    backButton->show();
}



void Settings::onBackButton()
{
    stateManager->popState();
}



void Settings::eventClosed()
{
    stateManager->resetState();
}

void Settings::eventMouseMoved(sf::Event::MouseMoveEvent &mouseMove)
{
    backButton->mouseMoved(mouseMove.x, mouseMove.y);
}

void Settings::eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton)
{
    backButton->click(mouseButton.x, mouseButton.y);
}


