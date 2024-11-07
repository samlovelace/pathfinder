
#include "Agent.h"


Agent::Agent(std::pair<int, int> aLocation) : 
                    Entity(aLocation, 1, 1, CellState::AGENT),
                    mGoal(new Entity(std::make_pair<int, int>(49, 49), 1, 1, CellState::GOAL))
{
}

Agent::~Agent()
{
}

