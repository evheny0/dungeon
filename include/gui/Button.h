#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Image.h"
#include "Text.h"
#include "Functor.h"


class Button {  // : public Drawable
    BasicFunctor *observer;
    Image *backgroundImage;
    Image *activeImage;
    Text *text;
    sf::Rect<int> activeArea;
    bool isActive;
  public:
    Button();
    Button(BasicFunctor *observer = NULL);
    ~Button();
    void setImages(Image *backgroundImage, Image *activeImage = 0);
    void setText(Text *font, int size = 30, int red = 0, int blue = 0, int green = 0, int alpha = 255);
    void setString(std::string &str);
    void setPosition(int x, int y);

    void mouseMoved(int x, int y);
    void click(int x, int y);

    void move(int x, int y);
    void setActive();
    void setInactive();
    void render();
};

#endif // BUTTON_H
