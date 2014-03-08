#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"


class Text : public Drawable {
    sf::Font *font;
    sf::Text text;

  public:
    Text();
    Text(sf::Font *font);
    ~Text();
    void setString(std::string &str);
    void setPosition(int x, int y);
    void setSize(int size);
    void setColor(int red, int blue, int green, int alpha = 255);
    void show();
};

#endif // TEXT_H
