#include "level.h"

int Level::getCurrentRoomID()
{
    return currentRoom.getX() * LVL_SIZE + currentRoom.getY();
}

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
    int* marker = new int [LVL_SIZE];
    for (int i = 0; i < LVL_SIZE; i++)
        marker[i] = i;
    for (int i = 0; i < LVL_SIZE; i++)
        for (int j = 0; j < LVL_SIZE; j++)
            rooms[i][j].clean();
    for (int i = 0; i < LVL_SIZE; i++)
        for (int j = 0; j < LVL_SIZE - 1; j++)
        {
            rooms[i][j].doorRight();
            rooms[i][j + 1].doorLeft();
        }
    for (int i = 0; i < LVL_SIZE - 1; i++)
        for (int j = 0; j < LVL_SIZE; j++)
        {
            rooms[i][j].doorDown();
            rooms[i + 1][j].doorUp();
        }
    int id = LVL_SIZE;
    for (int i = 0; i < LVL_SIZE - 1; i++)
    {
        for (int j = 0; j < LVL_SIZE - 1; j++)
        {
            if (marker[j] == marker[j + 1])
            {
                rooms[i][j].wallRight();
                rooms[i][j + 1].wallLeft();
            }
        }
        for (int j = 0; j < LVL_SIZE - 1; j++)
        {
            if (Dice::random(1))
            {
                rooms[i][j].wallRight();
                rooms[i][j + 1].wallLeft();
            }
            else
                marker[j + 1] = marker[j];
        }
        for (int j = 0; j < LVL_SIZE; j++)
        {
            if (Dice::random(1) && ((marker[j] == marker[j + 1] && !j) || (marker[j] == marker[j - 1] && j)))
            {
                rooms[i][j].wallDown();
                rooms[i + 1][j].wallUp();
                marker[j] = id++;
            }
        }
    }
    for (int j = 0; j < LVL_SIZE - 1; j++)
    {
        if (marker[j] == marker[j + 1])
        {
            rooms[LVL_SIZE - 1][j].wallRight();
            rooms[LVL_SIZE - 1][j + 1].wallLeft();
        }
    }
    int i, j, k;
    bool ready = false;
    while(!ready)
    {
        i = Dice::random(LVL_SIZE - 1);
        j = Dice::random(LVL_SIZE - 1);
        k = Dice::random(3);
        switch (k)
        {
        case 0:
            ready = rooms[i][j].wayinUp();
            break;
        case 1:
            ready = rooms[i][j].wayinRight();
            break;
        case 2:
            ready = rooms[i][j].wayinDown();
            break;
        case 3:
            ready = rooms[i][j].wayinLeft();
            break;
        }
    }
    ready = false;
    while(!ready)
    {
        i = Dice::random(LVL_SIZE - 1);
        j = Dice::random(LVL_SIZE - 1);
        k = Dice::random(3);
        switch (k)
        {
        case 0:
            ready = rooms[i][j].wayoutUp();
            break;
        case 1:
            ready = rooms[i][j].wayoutRight();
            break;
        case 2:
            ready = rooms[i][j].wayoutDown();
            break;
        case 3:
            ready = rooms[i][j].wayoutLeft();
            break;
        }
    }
//    rooms[LVL_SIZE - 1][LVL_SIZE - 1].wayinDown();
//    rooms[0][0].wayoutUp();
    delete []marker;
}

void Level::lvl0()
{
    rooms[0][0].clean();
    rooms[0][0].wayinDown();
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

void Level::setLvl(Room rooms[LVL_SIZE][LVL_SIZE], int interval, Coordinates currentRoom)
{
    for (int i = 0; i < LVL_SIZE; i++)
        for (int j = 0; j < LVL_SIZE; j++)
            this->rooms[i][j] = rooms[i][j];
    this->interval = interval;
    this->currentRoom = currentRoom;
}
