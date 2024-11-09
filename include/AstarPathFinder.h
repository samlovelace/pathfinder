#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H

#include "IPathFinder.h"

class AstarPathFinder : public IPathFinder
{
public:
    AstarPathFinder();
    ~AstarPathFinder() override;

    bool findPath(Grid& aGrid) override; 

private: 


};

#endif // ASTARPATHFINDER_H
