#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
public:
    Entity(/* args */);
    ~Entity();

    enum class EntityType
    {
        NONE = 0,
        OBSTACLE = -1,
        AGENT = 1,
        GOAL = 2
    };

    int x() { return mXPosition; }
    int y() { return mYPosition; }
    int width() { return mWidth; }
    int height() { return mHeight; }
    EntityType type() { return mType; }


private: 
    int mXPosition;
    int mYPosition;
    int mWidth;
    int mHeight;
    EntityType mType;

};

#endif // ENTITY_H

