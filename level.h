#ifndef LEVEL_H
#define LEVEL_H
#include <room.h>
#include <additionfunction.h>
#define LVL_SIZE 5 //4

class Level
{
    Room rooms[LVL_SIZE][LVL_SIZE];
    Coordinates currentRoom;
    int interval;
    void eller();
public:
    Level();
    void lvl0();
    int getCurrentRoomID();
    int* getInterval();
    void setLvl(Room rooms[LVL_SIZE][LVL_SIZE], int interval, Coordinates currentRoom);
    Room getRoom(int row, int column);
    Room getCurrentRoom();
    Coordinates getCurrentRoomCoord();
    Room changeCurrentRoom(int dRow, int dColumn);
    Room setCurrentRoom(int row, int column);
    typeCell getTypeCell(int x, int y);
    void generateLvl(Coordinates currentRoom);
    bool isFree(int x, int y);
};

#endif // LEVEL_H
