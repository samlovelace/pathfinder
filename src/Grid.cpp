#include "Grid.h"
#include <iostream>

Grid::Grid() : mGridHeight(50), mGridWidth(50), 
                            mGrid(mGridHeight, std::vector<Entity::CellState>(mGridWidth, Entity::CellState::EMPTY))
{

}

Grid::~Grid()
{

}

std::pair<int, int> Grid::getStart()
{
    for (int i = 0; i < mGridHeight; i++)
    {
        for (int j = 0; j < mGridWidth; j++)
        {
            if (Entity::CellState::AGENT == mGrid[i][j])
            {
                return std::make_pair(i, j);
            }
        }
    }

    return std::make_pair(-1, -1);
}

std::pair<int, int> Grid::getGoal()
{
    for (int i = 0; i < mGridHeight; i++)
    {
        for (int j = 0; j < mGridWidth; j++)
        {
            if (Entity::CellState::GOAL == mGrid[i][j])
            {
                return std::make_pair(i, j);
            }
        }
    }

    return std::make_pair(-1, -1);
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

bool Grid::addPath(std::vector<std::pair<int, int>> aPath)
{
    for(auto node : aPath)
    {
        if(!isLocationOnGrid(node.first, node.second))
        {
            return false;
        }

        mGrid[node.first][node.second] = Entity::CellState::AGENT;
    }

    return true;
}

bool Grid::addEntities(std::vector<Entity*> aVectorOfEntities)
{
    for(auto entity : aVectorOfEntities)
    {
        if(!isLocationOnGrid(entity->x(), entity->y()))
        {
            return false;
        }

        if(Entity::CellState::OBSTACLE == entity->type())
        {
            addObstacle(entity->x(), entity->y(), entity->width(), entity->height());
        }
        else if (Entity::CellState::AGENT == entity->type())
        {
            addAgent(entity->x(), entity->y());
        }
        else if (Entity::CellState::GOAL == entity->type())
        {
            addGoal(entity->x(), entity->y());
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

    mGrid[x][y] = Entity::CellState::OBSTACLE;
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

    mGrid[x][y] = Entity::CellState::AGENT;
    return true;
}

bool Grid::addGoal(int x, int y)
{
    if(x < 0 || x >= mGridWidth || y < 0 || y >= mGridHeight)
    {
        return false;
    }

    mGrid[x][y] = Entity::CellState::GOAL;
    return true;
}

bool Grid::isLocationOnGrid(int aX, int aY)
{
    return aX >= 0 && aX < mGridWidth && aY >= 0 && aY < mGridHeight;
}

