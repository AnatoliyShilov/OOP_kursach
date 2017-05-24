#include "room.h"

bool Room::isFree(int x, int y)
{
    if (cells[y][x].getType() == typeCell::WALL || x < 0 || y < 0 || x > 7 || y > 7)
        return false;
    return true;
}

void Room::wayin()
{
    cells[7][4].setCell(WAYIN);
}

void Room::wayout()
{
    cells[0][4].setCell(WAYOUT);
}

void Room::wallUp()
{
    cells[0][4].setCell(WALL);
}

void Room::wallDown()
{
    cells[7][4].setCell(WALL);
}

void Room::wallLeft()
{
    cells[4][0].setCell(WALL);
}

void Room::wallRight()
{
    cells[4][7].setCell(WALL);
}

void Room::doorUp()
{
    cells[0][4].setCell(DOOR);
}

void Room::doorDown()
{
    cells[7][4].setCell(DOOR);
}

void Room::doorLeft()
{
    cells[4][0].setCell(DOOR);
}

void Room::doorRight()
{
    cells[4][7].setCell(DOOR);
}

void Room::clean()
{
    for (int i = 1; i < 7; i++)
        for (int j = 1; j < 7; j++)
            cells[i][j].setCell(typeCell::FLOOR);
    for (int i = 0; i < 8; i++)
    {
        cells[0][i].setCell(typeCell::WALL);
        cells[7][i].setCell(typeCell::WALL);
        cells[i][0].setCell(typeCell::WALL);
        cells[i][7].setCell(typeCell::WALL);
    }
}

typeCell Room::getTypeCell(int x, int y)
{
    return cells[y][x].getType();
}

Cell** Room::getCells()
{
    Cell** cells = new Cell* [8];
    for (int i = 0; i < 8; i++)
        cells[i] = new Cell [8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cells[i][j] = this->cells[i][j];
    return cells;
}

Room::Room()
{

}

void Room::setRoom(Cell cells[8][8])
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            this->cells[i][j] = cells[i][j];
}
