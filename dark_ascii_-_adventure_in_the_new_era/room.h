#ifndef ROOM_H
#define ROOM_H
#include <cell.h>

class Room
{
    Cell cells[8][8];
    void createRoom();
public:
    Room();
};

#endif // ROOM_H
