
#include "Agent.h"
#include "BfsPathFinder.h"
#include "AstarPathFinder.h"
#include <cstdio>


Agent::Agent(std::pair<int, int> aLocation) : 
                    Entity(aLocation, 1, 1, CellState::AGENT),
                    mGoal(new Entity(std::make_pair<int, int>(49, 49), 1, 1, CellState::GOAL))
{
}

Agent::~Agent()
{
}

bool Agent::traverseGrid(Grid& aGrid)
{
    return mPathFinder->findPath(aGrid); 
}

std::unique_ptr<IPathFinder> Agent::createPathFinder(PathFinderType aType)
{
    std::unique_ptr<IPathFinder> pathFinderToReturn; 

    switch (aType)
    {
    case PathFinderType::BREADTHFIRSTSEARCH:
        pathFinderToReturn = std::make_unique<BfsPathFinder>(); 
        break;

    case PathFinderType::ASTAR: 
        pathFinderToReturn = std::make_unique<AstarPathFinder>();
        break;  
    
    default:
        printf("Unsupported PathFinderType\n");
        break;
    }

    return pathFinderToReturn; 
}

