#include "room.h"

bool Room::isFree(int x, int y)
{
    if (cells[y][x].getType() == typeCell::WALL || x < 0 || y < 0 || x > ROOM_SIZE - 1 || y > ROOM_SIZE - 1)
        return false;
    return true;
}

bool Room::wayinUp()
{
    if (cells[0][ROOM_SIZE / 2].getType() == typeCell::WALL)
    {
        cells[0][ROOM_SIZE / 2].setCell(WAYIN);
        return true;
    }
    return false;
}

bool Room::wayinDown()
{
    if (cells[ROOM_SIZE - 1][ROOM_SIZE / 2].getType() == typeCell::WALL)
    {
        cells[ROOM_SIZE - 1][ROOM_SIZE / 2].setCell(WAYIN);
        return true;
    }
    return false;
}

bool Room::wayinLeft()
{
    if (cells[ROOM_SIZE / 2][0].getType() == typeCell::WALL)
    {
        cells[ROOM_SIZE / 2][0].setCell(WAYIN);
        return true;
    }
    return false;
}

bool Room::wayinRight()
{
    if (cells[ROOM_SIZE / 2][ROOM_SIZE - 1].getType() == typeCell::WALL)
    {
        cells[ROOM_SIZE / 2][ROOM_SIZE - 1].setCell(WAYIN);
        return true;
    }
    return false;
}

bool Room::wayoutUp()
{
    if (cells[0][ROOM_SIZE / 2].getType() == typeCell::WALL)
    {
        cells[0][ROOM_SIZE / 2].setCell(WAYOUT);
        return true;
    }
    return false;
}

bool Room::wayoutDown()
{
    if (cells[ROOM_SIZE - 1][ROOM_SIZE / 2].getType() == typeCell::WALL)
    {
        cells[ROOM_SIZE - 1][ROOM_SIZE / 2].setCell(WAYOUT);
        return true;
    }
    return false;
}

bool Room::wayoutLeft()
{
    if (cells[ROOM_SIZE / 2][0].getType() == typeCell::WALL)
    {
        cells[ROOM_SIZE / 2][0].setCell(WAYOUT);
        return true;
    }
    return false;
}

bool Room::wayoutRight()
{
    if (cells[ROOM_SIZE / 2][ROOM_SIZE - 1].getType() == typeCell::WALL)
    {
        cells[ROOM_SIZE / 2][ROOM_SIZE - 1].setCell(WAYOUT);
        return true;
    }
    return false;
}

void Room::wallUp()
{
    cells[0][ROOM_SIZE / 2].setCell(WALL);
}

void Room::wallDown()
{
    cells[ROOM_SIZE - 1][ROOM_SIZE / 2].setCell(WALL);
}

void Room::wallLeft()
{
    cells[ROOM_SIZE / 2][0].setCell(WALL);
}

void Room::wallRight()
{
    cells[ROOM_SIZE / 2][ROOM_SIZE - 1].setCell(WALL);
}

void Room::doorUp()
{
    cells[0][ROOM_SIZE / 2].setCell(DOOR);
}

void Room::doorDown()
{
    cells[ROOM_SIZE - 1][ROOM_SIZE / 2].setCell(DOOR);
}

void Room::doorLeft()
{
    cells[ROOM_SIZE / 2][0].setCell(DOOR);
}

void Room::doorRight()
{
    cells[ROOM_SIZE / 2][ROOM_SIZE - 1].setCell(DOOR);
}

void Room::clean()
{
    for (int i = 1; i < ROOM_SIZE - 1; i++)
        for (int j = 1; j < ROOM_SIZE - 1; j++)
            cells[i][j].setCell(typeCell::FLOOR);
    for (int i = 0; i < ROOM_SIZE; i++)
    {
        cells[0][i].setCell(typeCell::WALL);
        cells[ROOM_SIZE - 1][i].setCell(typeCell::WALL);
        cells[i][0].setCell(typeCell::WALL);
        cells[i][ROOM_SIZE - 1].setCell(typeCell::WALL);
    }
}

typeCell Room::getTypeCell(int x, int y)
{
    return cells[y][x].getType();
}

Cell** Room::getCells()
{
    Cell** cells = new Cell* [ROOM_SIZE];
    for (int i = 0; i < ROOM_SIZE; i++)
        cells[i] = new Cell [ROOM_SIZE];
    for (int i = 0; i < ROOM_SIZE; i++)
        for (int j = 0; j < ROOM_SIZE; j++)
            cells[i][j] = this->cells[i][j];
    return cells;
}

Room::Room()
{

}

void Room::setRoom(Cell cells[ROOM_SIZE][ROOM_SIZE])
{
    for (int i = 0; i < ROOM_SIZE; i++)
        for (int j = 0; j < ROOM_SIZE; j++)
            this->cells[i][j] = cells[i][j];
}
