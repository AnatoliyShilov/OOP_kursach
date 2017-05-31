#include "cell.h"

typeCell Cell::getType()
{
    return type;
}

Cell::Cell()
{
    Cell::type = typeCell::FLOOR;
}

void Cell::setCell(typeCell type)
{
    this->type = type;
}
