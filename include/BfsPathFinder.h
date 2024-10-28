#ifndef BFS_PATH_FINDER_H
#define BFS_PATH_FINDER_H

#include <IPathFinder.h>

class BfsPathFinder : public IPathFinder
{
public:
    BfsPathFinder(/* args */);
    ~BfsPathFinder();

    bool findPath() override;

private:

};

#endif // BFS_PATH_FINDER_H
