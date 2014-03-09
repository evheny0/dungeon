#ifndef DRAWABLE_H
#define DRAWABLE_H


class Drawable {
  public:
    static sf::RenderWindow *window;
    virtual void show() = 0;
    virtual ~Drawable() { };
};

#endif // DRAWABLE_H
