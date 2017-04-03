#ifndef LEVEL_H
#define LEVEL_H
#include <room.h>

class Level
{
    int id;
    Room rooms[4][4];
    int interval[2];
    void createLevel();
public:
    Level();
    int* getInterval();
};

#endif // LEVEL_H
