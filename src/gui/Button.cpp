#include "gui/Button.h"

Button::Button(BasicFunctor *observer) : activeArea(0, 0, 0, 0)
{
    this->observer = observer;
    backgroundImage = NULL;
    activeImage = NULL;
    isActive = false;
}

Button::~Button()
{
    delete observer;
}

void Button::setImages(Image *backgroundImage, Image *activeImage)
{
    this->backgroundImage = backgroundImage;
    if (activeImage) {
        this->activeImage = activeImage;
    } else {
        this->activeImage = backgroundImage;
    }
}

void Button::setText(Text *text, int size, int red, int blue, int green, int alpha)
{
    this->text = text;
    this->text->setSize(size);
    this->text->setColor(red, blue, green, alpha);
}

void Button::setString(std::string &str)
{
    text->setString(str);
}



void Button::mouseMoved(int x, int y)
{
    if (activeArea.contains(x, y)) {
        setActive();
    } else {
        setInactive();
    }
}

void Button::click(int x, int y)
{
    if (observer && activeArea.contains(x, y)) {
        observer->notify();
    }
}



void Button::setPosition(int x, int y)
{
    backgroundImage->setPosition(x, y);
    activeImage->setPosition(x, y);
    text->setPosition(x + 7, y - 8);  // need to calculate using images params

    activeArea = backgroundImage->getTextureRect();
}

void Button::move(int x, int y)
{
    backgroundImage->move(x, y);
    activeImage->move(x, y);
}

void Button::setActive()
{
    isActive = true;
}

void Button::setInactive()
{
    isActive = false;
}

void Button::show()
{
    if (isActive) {
        activeImage->show();
    } else {
        backgroundImage->show();
    }
    if (text) {
        text->show();
    }
}
