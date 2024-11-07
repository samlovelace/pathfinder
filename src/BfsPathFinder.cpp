
#include "BfsPathFinder.h"
#include <algorithm>


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

    // push the start node onto the queue and mark as visited
    mQueue.push_back(start);
    mVisited[start.first][start.second] = true;

    while(!mQueue.empty())
    {
        //printVisited(grid);

        // get the front element of the queue and pop it
        std::pair<int, int> current = mQueue.front(); 
        mQueue.pop_front();

        if(current == goal)
        { 
            for(std::pair<int, int> node = goal; node != start; node = mParents[node])
            {
                mPath.push_back(node);
            }
            mPath.push_back(start);
            std::reverse(mPath.begin(), mPath.end());

            //printPath(grid); 
            grid.addPath(mPath);
            return true;
        }

        // check the neighbors
        for(auto& direction : mGridDirections)
        {
            int x = current.first + direction.first;
            int y = current.second + direction.second;

            // check if the neighbor is within the bounds of the grid
            if(x >= 0 && x < grid.getWidth() && y >= 0 && y < grid.getHeight())
            {
                // check if the neighbor is not visited and is not an obstacle
                if(!mVisited[x][y] && grid.getGrid()[x][y] != Entity::CellState::OBSTACLE)
                {
                    mQueue.push_back(std::make_pair(x, y));
                    mVisited[x][y] = true;
                    mParents[std::make_pair(x, y)] = current;
                }
            }
        }
    }

    return false; 
}


