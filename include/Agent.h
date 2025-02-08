#ifndef AGENT_H
#define AGENT_H

#include "Entity.h"
#include "IPathFinder.h"
#include <thread> 

class Agent : public Entity
{
public:
    Agent(std::pair<int, int> aLocation);
    ~Agent() override; 

    bool traverseGrid(Grid& aGrid); 

    Entity* getGoal() {return mGoal; }
    std::pair<int, int> getCurrentPos() {return mPathFinder->getCurrentPos(); }
    void setPathFinder(PathFinderType aType) {mPathFinder = createPathFinder(aType);}

private:
    Entity* mGoal; 
    std::unique_ptr<IPathFinder> mPathFinder;
    std::thread mFindPathThread; 

    std::unique_ptr<IPathFinder> createPathFinder(PathFinderType aType); 



};

#endif // AGENT_H

