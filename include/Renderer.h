#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

class Renderer
{
public:
    Renderer(/* args */);
    ~Renderer();

    void run(); 
    void renderGrid(sf::RenderWindow& window, Grid& aGrid);

    sf::Color getColorFromCellState(Grid::CellState aType);

private:

    sf::RenderWindow* mWindow;

};

#endif // RENDERER_H



