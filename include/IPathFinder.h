#ifndef IPATHFINDER_H
#define IPATHFINDER_H

#include "Grid.h"
#include <map> 
#include <vector>

class IPathFinder
{
public:

    virtual ~IPathFinder() = default; 
    virtual bool findPath(Grid& aGrid) = 0; 

protected:
    const std::vector<std::pair<int, int>> mGridDirections = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    std::vector<std::pair<int, int>> mPath; 

};

enum class PathFinderType
{
    BREADTHFIRSTSEARCH, 
    ASTAR, 
    NUM_TYPES
};

#endif // IPATHFINDER_H
