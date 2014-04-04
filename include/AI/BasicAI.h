#ifndef BASIC_AI_H
#define BASIC_AI_H

class Map;

class BasicAI {
  public:
    virtual ~BasicAI() {};
    virtual void updateState(Map *levelMap) = 0;
    
};

#endif // BASIC_AI_H
