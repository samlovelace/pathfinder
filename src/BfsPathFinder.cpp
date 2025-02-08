
#include "BfsPathFinder.h"
#include <algorithm>
#include <thread> 
#include <chrono> 
#include <iostream>

BfsPathFinder::BfsPathFinder(/* args */) : mQueue(), mVisited(50, std::vector<bool>(50, false))
{

}

BfsPathFinder::~BfsPathFinder()
{
}

bool BfsPathFinder::findPath(Grid& grid)
{
    std::pair<int, int> start = grid.getStart();
    std::pair<int, int> goal = grid.getGoal();

    // Initialize search
    mQueue.push_back(start);
    mVisited[start.first][start.second] = true;
    std::pair<int, int> lastMoveDirection = {0, 1}; // Start by assuming the robot moves to the right

    while (!mQueue.empty())
    {
        std::pair<int, int> current = mQueue.front();
        mQueue.pop_front();

        std::cout << "Current Position: " << current.first << ", " << current.second << std::endl;

        if (current == goal)
        {
            for (std::pair<int, int> node = goal; node != start; node = mParents[node])
            {
                mPath.push_back(node);
            }
            mPath.push_back(start);
            std::reverse(mPath.begin(), mPath.end());
            grid.addPath(mPath);
            return true;
        }

        // Introduce movement priority: favor last move direction
        std::vector<std::pair<int, int>> prioritizedDirections;
        prioritizedDirections.push_back(lastMoveDirection);

        for (auto &direction : mGridDirections)
        {
            if (direction != lastMoveDirection)
                prioritizedDirections.push_back(direction);
        }

        // Iterate over prioritized directions
        for (auto &direction : prioritizedDirections)
        {
            int x = current.first + direction.first;
            int y = current.second + direction.second;

            if (x >= 0 && x < grid.getWidth() && y >= 0 && y < grid.getHeight())
            {
                if (!mVisited[x][y] && grid.getGrid()[x][y] != Entity::CellState::OBSTACLE)
                {
                    mQueue.push_back(std::make_pair(x, y));
                    mVisited[x][y] = true;
                    mParents[std::make_pair(x, y)] = current;
                    setCurrentPos(std::make_pair(x, y));

                    // Update last movement direction
                    lastMoveDirection = direction;
                    break; // Make the robot move step-by-step instead of considering all options at once
                }
            }
        }

        // Simulate real-time movement (robot reaction delay)
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return false;
}



