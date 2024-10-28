#include "Grid.h"
#include <iostream>

Grid::Grid() : mGridHeight(20), mGridWidth(20), mGrid(mGridHeight, std::vector<Grid::CellState>(mGridWidth, Grid::CellState::EMPTY))
{

}

Grid::~Grid()
{

}

void Grid::print()
{
    for (int i = 0; i < mGridHeight; i++)
    {
        for (int j = 0; j < mGridWidth; j++)
        {
            std::cout << static_cast<int>(mGrid[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}

bool Grid::addEntities(std::vector<Entity> aVectorOfEntities)
{
    for(auto entity : aVectorOfEntities)
    {
        if(!isLocationOnGrid(entity.x, entity.y))
        {
            return false;
        }

        if(Grid::CellState::OBSTACLE == entity.type)
        {
            addObstacle(entity.x, entity.y, entity.width, entity.height);
        }
        else if (Grid::CellState::AGENT == entity.type)
        {
            addAgent(entity.x, entity.y);
        }
        else if (Grid::CellState::GOAL == entity.type)
        {
            addGoal(entity.x, entity.y);
        }
    }

    return true;
}


bool Grid::addSingleObstacle(int x, int y)
{
    if(x < 0 || x >= mGridWidth || y < 0 || y >= mGridHeight)
    {
        return false;
    }

    mGrid[x][y] = Grid::CellState::OBSTACLE;
    return true; 
}

bool Grid::addObstacle(int x, int y, int width, int height)
{
    for(int i = x; i < x + width; i++)
    {
        for(int j = y; j < y + height; j++)
        {
            addSingleObstacle(i, j);
        }
    }

    return true;
}

bool Grid::addAgent(int x, int y)
{
    if(x < 0 || x >= mGridWidth || y < 0 || y >= mGridHeight)
    {
        return false;
    }

    mGrid[x][y] = Grid::CellState::AGENT;
    return true;
}

bool Grid::addGoal(int x, int y)
{
    if(x < 0 || x >= mGridWidth || y < 0 || y >= mGridHeight)
    {
        return false;
    }

    mGrid[x][y] = Grid::CellState::GOAL;
    return true;
}

bool Grid::isLocationOnGrid(int aX, int aY)
{
    return aX >= 0 && aX < mGridWidth && aY >= 0 && aY < mGridHeight;
}

