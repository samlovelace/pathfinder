#ifndef OBSTACLESMANAGER_H
#define OBSTACLESMANAGER_H

#include <vector>
#include "Obstacle.h"

class ObstaclesManager
{
public:
    ObstaclesManager(int aNumberOfObstaclesToManage);
    ~ObstaclesManager();

    void generateObstacles(); 

    std::vector<Obstacle*> getObstacles() {return mObstacles;}

private:
    std::vector<Obstacle*> mObstacles; 
    int mNumberOfObstacles; 

};

#endif // OBSTACLESMANAGER_H
