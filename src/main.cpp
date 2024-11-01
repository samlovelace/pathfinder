
#include "SFML/Graphics.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Grid.h"
#include "Renderer.h"
#include "BfsPathFinder.h"


int main()
{
    Renderer* renderer = new Renderer();

    Grid::Entity agent = {0, 0, 1, 1, Grid::CellState::AGENT};
    Grid::Entity goal = {49, 49, 1, 1, Grid::CellState::GOAL};
    Grid::Entity obs = {0, 15, 4, 4, Grid::CellState::OBSTACLE};

    std::srand(std::time(nullptr));

    Grid::Entity obs2 = {std::rand() % 20, std::rand() % 20, std::rand() % 5 + 1, std::rand() % 5 + 1, Grid::CellState::OBSTACLE};
    Grid::Entity obs3 = {std::rand() % 50, std::rand() % 30, std::rand() % 5 + 1, std::rand() % 5 + 1, Grid::CellState::OBSTACLE};
    Grid::Entity obs4 = {std::rand() % 30, std::rand() % 50, std::rand() % 5 + 1, std::rand() % 5 + 1, Grid::CellState::OBSTACLE};
    Grid::Entity obs5 = {std::rand() % 20, std::rand() % 50, std::rand() % 5 + 1, std::rand() % 5 + 1, Grid::CellState::OBSTACLE};

    Grid::Entity obs6 = {std::rand() % 50, std::rand() % 50, std::rand() % 15 + 1, std::rand() % 15 + 1, Grid::CellState::OBSTACLE};
    Grid::Entity obs7 = {std::rand() % 50, std::rand() % 50, std::rand() % 15 + 1, std::rand() % 17 + 1, Grid::CellState::OBSTACLE};
    Grid::Entity obs8 = {std::rand() % 50, std::rand() % 50, std::rand() % 20 + 1, std::rand() % 12 + 1, Grid::CellState::OBSTACLE};
    Grid::Entity obs9 = {std::rand() % 50, std::rand() % 50, std::rand() % 19 + 1, std::rand() % 15 + 1, Grid::CellState::OBSTACLE};

    std::vector<Grid::Entity> entities;

    entities.push_back(agent); 
    entities.push_back(goal); 
    entities.push_back(obs); 
    entities.push_back(obs2);
    entities.push_back(obs3);
    entities.push_back(obs4);
    entities.push_back(obs5); 
    entities.push_back(obs6);
    entities.push_back(obs7);
    entities.push_back(obs8);
    entities.push_back(obs9);

    Grid::get()->addEntities(entities);

    BfsPathFinder* bfs = new BfsPathFinder(); 

    bfs->findPath(*Grid::get()); 
 
    renderer->run();
}