#ifndef BFS_PATH_FINDER_H
#define BFS_PATH_FINDER_H

#include <deque>
#include <vector>
#include <map>
#include <Grid.h>
#include "IPathFinder.h"

class BfsPathFinder : public IPathFinder
{
public:
    BfsPathFinder(/* args */);
    ~BfsPathFinder() override; 

    bool findPath(Grid& grid) override; 
    //void printPath(Grid& grid);
    //void printVisited(Grid& grid);


private:
    std::deque<std::pair<int, int>> mQueue;
    std::vector<std::vector<bool>> mVisited;
    std::map<std::pair<int, int>, std::pair<int, int>> mParents;
};

#endif // BFS_PATH_FINDER_H
