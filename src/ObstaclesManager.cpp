
#include "ObstaclesManager.h"
#include <ctime>
#include <cstdlib>

ObstaclesManager::ObstaclesManager(int aNumberOfObstaclesToManage) : mNumberOfObstacles(aNumberOfObstaclesToManage), mObstacles()
{
}

ObstaclesManager::~ObstaclesManager()
{
}

void ObstaclesManager::generateObstacles()
{
    std::srand(std::time(nullptr));

    for(int i = 0; i < mNumberOfObstacles; i++)
    {
        std::pair<int, int> location = std::make_pair<int, int>(std::rand() % 48, std::rand() % 48); 
        int height = std::rand() % 5; 
        int width = std::rand() % 5; 

        Obstacle* obst = new Obstacle(location, height, width); 
        mObstacles.push_back(obst); 
    }
}