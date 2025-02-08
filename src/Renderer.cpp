#include "Renderer.h"

Renderer::Renderer(Agent& agent) : mAgent(agent)
{
}

Renderer::~Renderer()
{
}

void Renderer::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "PATHFINDER");

    while(window.isOpen())
    {
        sf::Event event; 
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();
        renderGrid(window, *Grid::get());

        window.display();

    }
}

void Renderer::renderGrid(sf::RenderWindow& window, Grid& aGrid)
{
    std::vector<std::vector<Entity::CellState>> grid = aGrid.getGrid();

    // Get the window size and calculate the center
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f center(windowSize.x / 2.0f, windowSize.y / 2.0f);

    int cell_size = 15;

    int gridWidth = grid.size();
    int gridHeight = grid[0].size();

    // Define the grid offset to ensure it's centered
    float offsetX = center.x - (gridWidth* cell_size) / 2.0f;
    float offsetY = center.y - (gridHeight * cell_size) / 2.0f;

    for (int i = 0; i < gridWidth; i++) 
    {
        for (int j = 0; j < gridHeight; j++) 
        {
            sf::RectangleShape cell(sf::Vector2f(cell_size - 1, cell_size - 1)); // Slightly smaller for grid lines
            
            // Calculate the cell's position with the offset
            float x_position = offsetX + (i * cell_size);
            float y_position = offsetY + (j * cell_size);

            cell.setPosition(x_position, y_position);   // Use offset for centering
            cell.setFillColor(getColorFromCellState(grid[i][j])); // Set the color based on the cell state

            cell.setOutlineThickness(0.25);          // Create a grid-like outline
            cell.setOutlineColor(sf::Color::White);
            window.draw(cell); 
        }
    }

    sf::RectangleShape agent(sf::Vector2f(cell_size -1, cell_size-1));

    std::pair<int, int> pos = mAgent.getCurrentPos(); 

    float x = offsetX + (pos.first * cell_size); 
    float y = offsetY + (pos.second * cell_size); 
    agent.setPosition(x, y); 
    agent.setFillColor(sf::Color::Blue); 
    agent.setOutlineThickness(0.25);          // Create a grid-like outline
    agent.setOutlineColor(sf::Color::White);

    window.draw(agent); 

}

sf::Color Renderer::getColorFromCellState(Entity::CellState aState)
{
    switch (aState)
    {
    case Entity::CellState::EMPTY:
        return sf::Color::Black;
        break;
    case Entity::CellState::OBSTACLE:
        return sf::Color::Red;
        break;
    case Entity::CellState::AGENT:
        return sf::Color::Blue;
        break;
    case Entity::CellState::GOAL:
        return sf::Color::Green;
        break;
    default:
        return sf::Color::Black;
        break;
    }
}

