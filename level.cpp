#include "level.h"

bool Level::isFree(int x, int y)
{
    return rooms[currentRoom.getX()][currentRoom.getY()].isFree(x, y);
}

typeCell Level::getTypeCell(int x, int y)
{
    return rooms[currentRoom.getX()][currentRoom.getY()].getTypeCell(x, y);
}

Room Level::setCurrentRoom(int row, int column)
{
    currentRoom.setCoords(row, column);
    return getCurrentRoom();
}

Coordinates Level::getCurrentRoomCoord()
{
    return currentRoom;
}

Room Level::changeCurrentRoom(int dRow, int dColumn)
{
    currentRoom.changeCoords(dRow, dColumn);
    return getCurrentRoom();
}

void Level::eller()
{
    Dice::init();
    int* marker = new int [4];
    for (int i = 0; i < 4; i++)
        marker[i] = i;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            rooms[i][j].clean();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
        {
            rooms[i][j].doorRight();
            rooms[i][j + 1].doorLeft();
        }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
        {
            rooms[i][j].doorDown();
            rooms[i + 1][j].doorUp();
        }
    int id = 4;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (marker[j] == marker[j + 1])
            {
                rooms[i][j].wallRight();
                rooms[i][j + 1].wallLeft();
            }
        }
        for (int j = 0; j < 3; j++)
        {
            if (Dice::random(1))
            {
                rooms[i][j].wallRight();
                rooms[i][j + 1].wallLeft();
            }
            else
                marker[j + 1] = marker[j];
        }
        for (int j = 0; j < 4; j++)
        {
            if (Dice::random(1) && ((marker[j] == marker[j + 1] && !j) || (marker[j] == marker[j - 1] && j)))
            {
                rooms[i][j].wallDown();
                rooms[i + 1][j].wallUp();
                marker[j] = id++;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (marker[j] == marker[j + 1])
        {
            rooms[3][j].wallRight();
            rooms[3][j + 1].wallLeft();
        }
    }
    rooms[3][3].wayin();
    rooms[0][0].wayout();
    delete []marker;
}

void Level::lvl0()
{
    rooms[0][0].clean();
    rooms[0][0].wayin();
    currentRoom.setCoords(0, 0);
}

Room Level::getCurrentRoom()
{
    return this->rooms[currentRoom.getX()][currentRoom.getY()];
}

Room Level::getRoom(int row, int column)
{
    return this->rooms[row][column];
}

Level::Level()
{
    Level::interval = 0;
}

void Level::generateLvl(Coordinates currentRoom)
{
    eller();
    this->currentRoom = currentRoom;
}

void Level::setLvl(Room rooms[4][4], int interval, Coordinates currentRoom)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->rooms[i][j] = rooms[i][j];
    this->interval = interval;
    this->currentRoom = currentRoom;
}
