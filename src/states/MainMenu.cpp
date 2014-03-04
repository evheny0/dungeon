#include "states/MainMenu.h"

MainMenu::MainMenu(StateManager *stateManager) : IState(stateManager)
{
    initButtons();
}

MainMenu::~MainMenu()
{

}

void MainMenu::initButtons()
{
    buttons.push_back(newButton("START"));
    buttons.push_back(newButton("SETTINGS"));
    buttons.push_back(newButton("QUIT"));

    buttons[0]->setPosition(300, 100);
    buttons[1]->setPosition(300, 200);
    buttons[2]->setPosition(300, 300);
}

Button *MainMenu::newButton(std::string str)
{
    Button *returnButton = new Button(new Functor<MainMenu>(this, &MainMenu::onExit));
    returnButton->setImages(Game::assetManager->getImage(buttonID), Game::assetManager->getImage(button_inactiveID));
    returnButton->setText(Game::assetManager->getText(digiffitiID));
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

void MainMenu::render()
{
    for (it = buttons.begin(); it != buttons.end(); ++it) {
        (*it)->render();
    }
}

void MainMenu::onExit()
{
    stateManager->resetState();
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
