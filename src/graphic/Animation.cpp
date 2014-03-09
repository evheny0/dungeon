#include "graphic/Animation.h"

Animation::Animation(sf::Texture &texture) : Image(texture)
{

}

Animation::Animation(Image &image) : Image(image)
{

}

Animation::~Animation()
{

}


void Animation::addFrame(int x, int y, int width, int height)
{
    frames.push_back(sf::IntRect(x, y, width, height));
}

void Animation::play()
{
    currentFrame = frames.begin();
    sprite.setTextureRect(*currentFrame); 
}

void Animation::updateFrame()
{
    if (clock.getElapsedTime().asMilliseconds() >= FRAME_TIME) {
        currentFrame++;
        if (currentFrame == frames.end()) {
            currentFrame = frames.begin();
        }
        sprite.setTextureRect(*currentFrame);
        clock.restart();
    }
}

void Animation::show()
{
    window->draw(sprite);
    updateFrame();
}
