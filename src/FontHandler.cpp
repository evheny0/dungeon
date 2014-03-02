#include "FontHandler.h"

FontHandler::FontHandler()
{
    fonts[o4bID] = newFont(o4bID);
    fonts[digiffitiID] = newFont(digiffitiID);
    fonts[m12ID] = newFont(m12ID);
}

FontHandler::~FontHandler()
{
    std::map<ImageID, sf::Font *>::iterator it;
    for (it = fonts.begin(); it != fonts.end(); ++it) {
        delete it->second;
    }
}

Text *FontHandler::getText(FontID &font)
{
    sf::Font *currentFont = fonts[font];
    if (!currentFont) {
        throw "Font not found";
    }
    return new Text(currentFont);
}

sf::Font *FontHandler::newFont(FontID &path)
{
    sf::Font *returnFont = new sf::Font();
    returnFont->loadFromFile(path);
    return returnFont;
}
