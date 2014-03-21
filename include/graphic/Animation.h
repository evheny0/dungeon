#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include "CoreTypes.h"
#include "Image.h"


class Animation : public Image {
    sf::Clock clock;
    std::vector<sf::IntRect> frames;
    std::vector<sf::IntRect>::iterator currentFrame;
  public:
    Animation(sf::Texture &texture);
    Animation(Image &image);
    ~Animation();
    void addFrame(int x, int y, int width, int height);
    void play();
    void updateFrame();
    int getWidth();
    int getHeight();


    void show();
};

#endif // ANIMATION_H