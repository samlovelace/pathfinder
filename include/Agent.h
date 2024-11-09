#ifndef AGENT_H
#define AGENT_H

#include "Entity.h"
#include "IPathFinder.h"
#include <memory>

class Agent : public Entity
{
public:
    Agent(std::pair<int, int> aLocation);
    ~Agent() override; 

    bool traverseGrid(Grid& aGrid); 

    Entity* getGoal() {return mGoal; }
    void setPathFinder(PathFinderType aType) {mPathFinder = createPathFinder(aType);}

private:
    Entity* mGoal; 
    std::unique_ptr<IPathFinder> mPathFinder;

    std::unique_ptr<IPathFinder> createPathFinder(PathFinderType aType); 

};

#endif // AGENT_H

