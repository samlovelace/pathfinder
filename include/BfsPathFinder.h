#ifndef BFS_PATH_FINDER_H
#define BFS_PATH_FINDER_H

#include <deque>
#include <vector>
#include <map>
#include <Grid.h>

class BfsPathFinder
{
public:
    BfsPathFinder(/* args */);
    ~BfsPathFinder();

    bool findPath(Grid& grid); 
    void printPath(Grid& grid);
    void printVisited(Grid& grid);


private:
    std::deque<std::pair<int, int>> mQueue;
    std::vector<std::vector<bool>> mVisited;
    const std::vector<std::pair<int, int>> mGridDirections = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    std::vector<std::pair<int, int>> mPath;
    std::map<std::pair<int, int>, std::pair<int, int>> mParents;
};

#endif // BFS_PATH_FINDER_H
