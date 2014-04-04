#ifndef ENTITY_H
#define ENTITY_H

#include "graphic/Image.h"
#include "graphic/Animation.h"
#include "Assets.h"

class Map;

class Entity {
  protected:
    int velocity;
    int x, y;     // coords
    int dx, dy;   // offset for move
    Image *currentImage;

    Image *stayRight;
    Image *stayLeft;
    Animation *moveRightAnimation;
    Animation *moveLeftAnimation;
  public:
    Entity();
    virtual ~Entity();
    virtual void act(Map *levelMap) { };

    int getX();
    int getY();
    void setPosition(int x, int y);
    void setVelocity(int vel);
    void stop();
    void move();
    void rollback();
    void show();

    void runUp();
    void runDown();
    void runRight();
    void runLeft();
    void stopUp();
    void stopDown();
    void stopRight();
    void stopLeft();

    bool isEnemy(Entity *opponent);
};

#endif // ENTITY_H
