#ifndef ROOM_H
#define ROOM_H
#include <cell.h>

class Room
{
    Cell cells[8][8];
    void createRoom();
public:
    Room();
    void clean();
    void doorUp();
    void doorDown();
    void doorLeft();
    void doorRight();
    void wallUp();
    void wallDown();
    void wallLeft();
    void wallRight();
    void wayin();
    void wayout();
    void setRoom(Cell cells[8][8]);
    Cell** getCells();
    typeCell getTypeCell(int x, int y);
    bool isFree(int x, int y);
};

#endif // ROOM_H
