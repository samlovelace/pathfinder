
#include "SFML/Graphics.hpp"

#include <iostream>

#include "Grid.h"
#include "Renderer.h"


int main()
{
    Renderer* renderer = new Renderer();

    std::vector<Grid::Entity> entities = {
        {5, 5, 1, 1, Grid::CellState::AGENT},
        {15, 15, 1, 1, Grid::CellState::GOAL}, 
        {10, 10, 5, 5, Grid::CellState::OBSTACLE}
    };

    Grid::get()->addEntities(entities);
 
    renderer->run();
}