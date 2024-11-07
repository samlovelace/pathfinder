
#include "Entity.h"
#include "Grid.h"
#include "Renderer.h"
#include "BfsPathFinder.h"
#include "ObstaclesManager.h"
#include "Agent.h"

int main()
{
    ObstaclesManager* obsMan = new ObstaclesManager(75); 
    Renderer* renderer = new Renderer();
    Agent* agent = new Agent(std::make_pair<int, int>(0, 0)); 
    BfsPathFinder* bfs = new BfsPathFinder();

    obsMan->generateObstacles();

    std::vector<Entity*> entities; 

    entities.push_back(agent); 
    entities.push_back(agent->getGoal());

    for(auto obs : obsMan->getObstacles())
    {
        entities.push_back(obs); 
    }

    Grid::get()->addEntities(entities); 

    if(!bfs->findPath(*Grid::get()))
    {
        printf("NO PATH TO GOAL EXISTS\n"); 
    } 

    renderer->run(); 
}