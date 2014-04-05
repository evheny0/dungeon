#ifndef FONT_HANDLER_H
#define FONT_HANDLER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "Assets.h"


class FontHandler {
    std::map<FontID, sf::Font *> fonts;
  public:
    FontHandler();
    ~FontHandler();
    sf::Font *getSfmlFont(FontID fontID);

  private:
    sf::Font *newFont(FontID &path);
};

#endif // FONT_HANDLER_H
