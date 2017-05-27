#ifndef ROOM_H
#define ROOM_H
#include <cell.h>
#define ROOM_SIZE 10    //8

class Room
{
    Cell cells[ROOM_SIZE][ROOM_SIZE];
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

    bool wayinUp();
    bool wayinDown();
    bool wayinLeft();
    bool wayinRight();

    bool wayoutUp();
    bool wayoutDown();
    bool wayoutLeft();
    bool wayoutRight();

    void setRoom(Cell cells[ROOM_SIZE][ROOM_SIZE]);
    Cell** getCells();
    typeCell getTypeCell(int x, int y);
    bool isFree(int x, int y);
};

#endif // ROOM_H
