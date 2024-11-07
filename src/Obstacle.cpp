
#include "Obstacle.h"

Obstacle::Obstacle(std::pair<int, int> aLocation, int aHeight, int aWidth) : Entity(aLocation, aHeight, aWidth, CellState::OBSTACLE)
{
}

Obstacle::~Obstacle()
{
}
