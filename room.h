#ifndef ROOM_H
#define ROOM_H
#include <cell.h>
#define ROOM_SIZE 10    //длинна и ширина комнаты

class Room//комната
{
    Cell cells[ROOM_SIZE][ROOM_SIZE];//ячейки комнаты
    void createRoom();//создать комнату
public:
    Room();
    void clean();//очистить комнату

    void doorUp();//установить дверь сверху
    void doorDown();//установить дверь снизу
    void doorLeft();//установить дверь слева
    void doorRight();//установить дверь справа

    void wallUp();//установить стену сверху
    void wallDown();//установить стену снизу
    void wallLeft();//установить стену слева
    void wallRight();//установить стену справа

    bool wayinUp();//установить переход на след. уровеню сверху
    bool wayinDown();//установить преход на след. уровень снизу
    bool wayinLeft();//установить переход на след. уровень слева
    bool wayinRight();//установить переход на след. уровень справа

    bool wayoutUp();//установить переход на пред. уровеню сверху
    bool wayoutDown();//установить преход на пред. уровень снизу
    bool wayoutLeft();//установить преход на пред. уровень слева
    bool wayoutRight();//установить преход на пред. уровень справа

    void setRoom(Cell cells[ROOM_SIZE][ROOM_SIZE]);//установить комнату
    Cell** getCells();
    typeCell getTypeCell(int x, int y);//вернуть тип ячейки
    bool isFree(int x, int y);//истинна, если ячейка не стена
};

#endif // ROOM_H
