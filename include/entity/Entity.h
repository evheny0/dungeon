#ifndef ENTITY_H
#define ENTITY_H

#include "graphic/Image.h"
#include "Assets.h"


class Entity {
  protected:
    int velocity;
    int x, y;     // coords
    int dx, dy;   // offset for move
    Image *currentImage;
  public:
    Entity();
    virtual ~Entity();

    int getX();
    int getY();
    void setPosition(int x, int y);
    void setVelocity(int vel);
    void stop();
    void move();
    void rollback();
    void show();
};


#endif // ENTITY_H
