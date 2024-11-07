#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Entity.h"

class Obstacle : public Entity
{
public:
    Obstacle(std::pair<int, int> aLocation, int aHeight, int aWidth);
    ~Obstacle() override; 

private:

};

#endif // OBSTACLE_H 
