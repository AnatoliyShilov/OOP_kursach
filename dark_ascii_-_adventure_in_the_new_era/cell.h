#ifndef CELL_H
#define CELL_H
#include <coordinates.h>
enum typeCell{
    TRAP,
    FLOOR,
    WALL,
    DOOR,
    IN,
    OUT
};

class Cell
{
    Coordinates coords;
    typeCell type;
public:
    Cell();
};

#endif // CELL_H
