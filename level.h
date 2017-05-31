#ifndef LEVEL_H
#define LEVEL_H
#include <room.h>
#include <additionfunction.h>
#define LVL_SIZE 5 //длинны и ширина уровня

class Level//уровень
{
    Room rooms[LVL_SIZE][LVL_SIZE];//комнаты
    Coordinates currentRoom;//координаты текущей комнаты
    void eller();//алгоритм генерации лабиринтов Эйлера
public:
    Level();
    void lvl0();//учтановить уровень 0
    int getCurrentRoomID();//рассчитать и вернуть идентификатор текущей комнаты
    void setLvl(Room rooms[LVL_SIZE][LVL_SIZE], Coordinates currentRoom);//установить уровень
    Room getRoom(Coordinates coord);//вернуть комнату с указанными координатами
    Room getCurrentRoom();//вернуть текущую комнату
    Coordinates getCurrentRoomCoord();//вернуть координаты текущей комнаты
    Room changeCurrentRoom(Coordinates dCoord);//изменить текущую комнату и вернуть ее
    Room setCurrentRoom(Coordinates coord);//установить текущую комнату
    typeCell getTypeCell(Coordinates coord);//вернуть тип ячеуки в комнате
    void generateLvl(Coordinates currentRoom);//сгенерировать новый уровень
    bool isFree(Coordinates coord);//истинна, если ячейка не стена
};

#endif // LEVEL_H
