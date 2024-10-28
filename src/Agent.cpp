
#include "Agent.h"
#include "BfsPathFinder.h"

Agent::Agent(/* args */) : mPathFinder(std::make_unique<BfsPathFinder>())
{
}

Agent::~Agent()
{
}



