#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Agent.h"

class Renderer
{
public:
    Renderer(Agent& anAgent);
    ~Renderer();

    void run(); 
    void renderGrid(sf::RenderWindow& window, Grid& aGrid);

    sf::Color getColorFromCellState(Entity::CellState aType);

private:
    sf::RenderWindow* mWindow;
    Agent& mAgent; 

};

#endif // RENDERER_H



