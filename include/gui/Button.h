#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Image.h"


class Button {  // : public Drawable
    Image *backgroundImage;
    Image *activeImage;
    std::string text;
    bool isActive;
    sf::Rect<int> activeArea;
  public:
    Button();
    Button(std::string text, Image *backgroundImage, Image *activeImage = 0);
    ~Button();
    void setImages(Image *backgroundImage, Image *activeImage = 0);
    void setText(std::string text);
    void setTextAndImages(std::string text, Image *backgroundImage, Image *activeImage = 0);
    void setPosition(int x, int y);
    void move(int x, int y);
    void setActive();
    void setInactive();
    void render();
};

#endif // BUTTON_H
