#include "graphic/Animation.h"

Animation::Animation(ImageID imageID) : Image(imageID)
{

}

Animation::~Animation()
{

}



void Animation::split(int frameWidth)
{
    for (int i = 0; i < sprite.getTextureRect().width / frameWidth; i++) {
        addFrame(i * frameWidth, 0, frameWidth, sprite.getTextureRect().height);
    }
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

int Animation::getWidth()
{
    return frames.begin()->width;
}

int Animation::getHeight()
{
    return frames.begin()->height;
}
