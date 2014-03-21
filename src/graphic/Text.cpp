#include "graphic/Text.h"

Text::Text()
{

}

Text::Text(sf::Font *font)
{
    this->font = font;
    text.setFont(*font);
}

Text::~Text()
{

}



void Text::setString(std::string &str)
{
    text.setString(str);
}

void Text::setPosition(int x, int y)
{
    text.setPosition(x, y);
}

void Text::setSize(int size)
{
    text.setCharacterSize(size);
}

void Text::setColor(int red, int blue, int green, int alpha)
{
    text.setColor(sf::Color(red, blue, green, alpha));
}

void Text::show()
{
    window->draw(text);
}
