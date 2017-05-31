#ifndef LEVEL_H
#define LEVEL_H
#include <room.h>
#include <additionfunction.h>
#define LVL_SIZE 5 //������ � ������ ������

class Level//�������
{
    Room rooms[LVL_SIZE][LVL_SIZE];//�������
    Coordinates currentRoom;//���������� ������� �������
    void eller();//�������� ��������� ���������� ������
public:
    Level();
    void lvl0();//���������� ������� 0
    int getCurrentRoomID();//���������� � ������� ������������� ������� �������
    void setLvl(Room rooms[LVL_SIZE][LVL_SIZE], Coordinates currentRoom);//���������� �������
    Room getRoom(Coordinates coord);//������� ������� � ���������� ������������
    Room getCurrentRoom();//������� ������� �������
    Coordinates getCurrentRoomCoord();//������� ���������� ������� �������
    Room changeCurrentRoom(Coordinates dCoord);//�������� ������� ������� � ������� ��
    Room setCurrentRoom(Coordinates coord);//���������� ������� �������
    typeCell getTypeCell(Coordinates coord);//������� ��� ������ � �������
    void generateLvl(Coordinates currentRoom);//������������� ����� �������
    bool isFree(Coordinates coord);//�������, ���� ������ �� �����
};

#endif // LEVEL_H
