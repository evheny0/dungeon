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

sf::Font *FontHandler::getSfmlFont(FontID fontID)
{
    sf::Font *returnFont = fonts[fontID];
    if (!returnFont) {
        throw "Font not found";
    }
    return returnFont;

}

sf::Font *FontHandler::newFont(FontID &path)
{
    sf::Font *returnFont = new sf::Font();
    returnFont->loadFromFile(path);
    return returnFont;
}
