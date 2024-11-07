#ifndef ENTITY_H
#define ENTITY_H

#include <map>

class Entity
{

public:
    
    enum CellState
    {
        EMPTY = 0,
        OBSTACLE = -1,
        AGENT = 1,
        GOAL = 2
    };
    
    Entity(std::pair<int, int> aLocation, int aHeight, int aWidth, CellState aType) : 
                            mLocation(aLocation), mHeight(aHeight), mWidth(aWidth), mType(aType) {} 
    virtual ~Entity() = default; 

    std::pair<int, int> getLocation() {return mLocation; }
    int x() {return mLocation.first; }
    int y() {return mLocation.second;}
    int height() {return mHeight; }
    int width() {return mWidth; }
    CellState type() {return mType; }
    Entity* getEntity() {return this;}

protected:
    std::pair<int, int> mLocation; 
    int mHeight; 
    int mWidth; 
    CellState mType; 

};

#endif // ENTITY_H

