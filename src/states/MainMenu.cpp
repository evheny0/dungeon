#include "states/MainMenu.h"

MainMenu::MainMenu(StateManager *stateManager) : IState(stateManager)
{
    initButtons();
}

MainMenu::~MainMenu()
{
    // cleaning up buttons

}

void MainMenu::initButtons()
{
    buttons.push_back(newButton("START", &MainMenu::onStartGame));
    buttons.push_back(newButton("SETTINGS", &MainMenu::onSettings));
    buttons.push_back(newButton("QUIT", &MainMenu::onExit));

    buttons[0]->setPosition(300, 100);
    buttons[1]->setPosition(300, 200);
    buttons[2]->setPosition(300, 300);
}

Button *MainMenu::newButton(std::string str, void(MainMenu::*callback)())
{
    Button *returnButton = new Button(new Functor<MainMenu>(this, callback));
    returnButton->setImages(new Image(buttonID), new Image(button_inactiveID));
    returnButton->setText(new Text(digiffitiID));
    returnButton->setString(str);
    return returnButton;
}



void MainMenu::input(sf::Event &event)
{
    inputEvent(event);
}

void MainMenu::update()
{

}

void MainMenu::show()
{
    for (it = buttons.begin(); it != buttons.end(); ++it) {
        (*it)->show();
    }
}



void MainMenu::onExit()
{
    stateManager->resetState();
}

void MainMenu::onSettings()
{
    stateManager->pushState(new Settings(stateManager));
}

void MainMenu::onStartGame()
{
    stateManager->setNextState(new GameState(stateManager));
}



void MainMenu::eventMouseMoved(sf::Event::MouseMoveEvent &mouseMove)
{
    for (it = buttons.begin(); it != buttons.end(); ++it) {
        (*it)->mouseMoved(mouseMove.x, mouseMove.y);
    }
}

void MainMenu::eventClosed()
{
    stateManager->resetState();
}

void MainMenu::eventLeftMouseButtonPressed(sf::Event::MouseButtonEvent &mouseButton)
{
    for (it = buttons.begin(); it != buttons.end(); ++it) {
        (*it)->click(mouseButton.x, mouseButton.y);
    }
}
