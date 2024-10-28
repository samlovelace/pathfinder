#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H

#include <IPathFinder.h>

class AstarPathFinder : public IPathFinder
{
public:
    AstarPathFinder(/* args */);
    ~AstarPathFinder();

    bool findPath() override;

private:
    /* data */
};

#endif // ASTARPATHFINDER_H
