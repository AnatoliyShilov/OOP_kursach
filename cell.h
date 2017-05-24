#ifndef CELL_H
#define CELL_H
#include <coordinates.h>
enum typeCell
{
    TRAP,
    FLOOR,
    WALL,
    DOOR,
    WAYIN,
    WAYOUT
};

class Cell
{
    typeCell type;
public:
    Cell();
    void setCell(typeCell type);
    typeCell getType();
};

#endif // CELL_H
