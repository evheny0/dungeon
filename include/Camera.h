#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include "graphic/Drawable.h"

class Camera : public Drawable {
    sf::View view;
  public:
    Camera();
    ~Camera();

    void setDefault();
    void reset(int x, int y, int width, int height);
    void zoom(float value);
    void rotate(int angle);
    void setViewport(float x, float y, float width, float height);
    void move(int x, int y);
    void setCenter(int x, int y);

    void apply();

    void show() {};
};

#endif // CAMERA_H
