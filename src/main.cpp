
#include "Entity.h"
#include "Grid.h"
#include "Renderer.h"
#include "BfsPathFinder.h"
#include "ObstaclesManager.h"
#include "Agent.h"

int main()
{
    auto obsMan = std::make_unique<ObstaclesManager>(125); 
    auto start = std::make_pair(0, 0); 
    auto agent = new Agent(start); 

    agent->setPathFinder(PathFinderType::BREADTHFIRSTSEARCH); 

    obsMan->generateObstacles();

    std::vector<Entity*> entities; 

    entities.push_back(agent); 
    entities.push_back(agent->getGoal());

    for(auto obs : obsMan->getObstacles())
    {
        entities.push_back(obs); 
    }

    Grid::get()->addEntities(entities); 

    if(!agent->traverseGrid(*Grid::get()))
    {
        printf("NO PATH TO GOAL EXISTS\n"); 
    } 

    auto renderer = std::make_unique<Renderer>();
    renderer->run();
    delete agent; 
}