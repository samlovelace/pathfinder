#ifndef AGENT_H
#define AGENT_H

#include <memory>
#include <IPathFinder.h>

class Agent
{
public:
    Agent(/* args */);
    ~Agent();

    void findPath(); 

private:
    std::unique_ptr<IPathFinder> mPathFinder;

};

#endif // AGENT_H

