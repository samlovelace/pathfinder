#ifndef IPATHFINDER_H
#define IPATHFINDER_H

#include "Grid.h"
#include <map> 
#include <vector>
#include <mutex> 
#include <thread> 

class IPathFinder
{
public:

    virtual ~IPathFinder() = default; 

    void start(Grid& aGrid) {std::thread(&IPathFinder::findPath, this, std::ref(aGrid)).detach(); }

    virtual bool findPath(Grid& aGrid) = 0; 

    void setCurrentPos(std::pair<int, int> aCurrentPos) {std::lock_guard<std::mutex> lock(mCurrentPosMtx); mCurrentPos = aCurrentPos; }
    std::pair<int, int> getCurrentPos() {std::lock_guard<std::mutex> lock(mCurrentPosMtx); return mCurrentPos; }


protected:
    const std::vector<std::pair<int, int>> mGridDirections = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const std::vector<std::pair<int, int>> mGridDirectionsWithDiag = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    std::vector<std::pair<int, int>> mPath; 

    std::pair<int, int> mCurrentPos; 
    std::mutex mCurrentPosMtx; 

};

enum class PathFinderType
{
    BREADTHFIRSTSEARCH, 
    ASTAR, 
    NUM_TYPES
};

#endif // IPATHFINDER_H
