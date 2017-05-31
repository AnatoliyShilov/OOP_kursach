#ifndef CELL_H
#define CELL_H
#include <coordinates.h>
enum typeCell//“ип €чейки
{
    TRAP,//ловвушка
    FLOOR,//пол
    WALL,//стена
    DOOR,//дверь
    WAYIN,//след. уровень
    WAYOUT//пред. уровень
};

class Cell//€чейка комнаты
{
    typeCell type;//тип €чейки
public:
    Cell();
    void setCell(typeCell type);//установить тип €чейки
    typeCell getType();//вернуть тип €чейки
};

#endif // CELL_H
