#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Entity.h"

class Grid
{
public:
    static Grid* get()
    {
        static Grid* instance = new Grid(); 
        return instance;
    }

    void print();

    bool addSingleObstacle(int x, int y);
    bool addObstacle(int x, int y, int width, int height);

    int getHeight() { return mGridHeight; }
    int getWidth() { return mGridWidth; }
    std::pair<int, int> getStart();
    std::pair<int, int> getGoal();

    std::vector<std::vector<Entity::CellState>>& getGrid() { return mGrid; }

    bool addPath(std::vector<std::pair<int, int>> aPath);

    bool addAgent(int x, int y);
    bool addGoal(int x, int y);

    bool addEntities(std::vector<Entity*> aVectorOfEntities);

private:
    Grid();
    ~Grid();

    Grid(Grid const&) = delete;
    void operator=(Grid const&) = delete;

    // Methods 
    bool isLocationOnGrid(int x, int y);

    // GRID DIMENSIONS
    int mGridHeight;
    int mGridWidth;

    // THE GRID 
    std::vector<std::vector<Entity::CellState>> mGrid; 

    // THE ENTITIES
    //std::vector<Entity*> mEntities;

};

#endif // GRID_H
