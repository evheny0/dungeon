#include "gui/Button.h"

Button::Button() : activeArea(0, 0, 0, 0)
{
    backgroundImage = NULL;
    activeImage = NULL;
    isActive = false;
}

Button::Button(std::string text, Image *backgroundImage, Image *activeImage)
{
    setTextAndImages(text, backgroundImage, activeImage);
}

Button::~Button()
{

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

void Button::setText(std::string text)
{
    this->text = text;
}

void Button::setTextAndImages(std::string text, Image *backgroundImage, Image *activeImage)
{
    setImages(backgroundImage, activeImage);
    setText(text);
}



void Button::setPosition(int x, int y)
{
    backgroundImage->setPosition(x, y);
    activeImage->setPosition(x, y);

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

void Button::render()
{
    if (isActive) {
        activeImage->show();
    } else {
        backgroundImage->show();
    }
}
