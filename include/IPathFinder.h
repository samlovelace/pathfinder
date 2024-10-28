#ifndef PATHFINDER_H
#define PATHFINDER_H

class IPathFinder
{
public:
    IPathFinder(/* args */);
    ~IPathFinder();

    virtual bool findPath() = 0; 

private:
    /* data */


};

#endif // PATHFINDER_H
