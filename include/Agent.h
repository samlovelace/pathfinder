#ifndef AGENT_H
#define AGENT_H

#include "Entity.h"

class Agent : public Entity
{
public:
    Agent(std::pair<int, int> aLocation);
    ~Agent() override; 

    Entity* getGoal() {return mGoal; }

private:
    Entity* mGoal; 
    ///IPathFinder* mPathFinder;

};

#endif // AGENT_H

