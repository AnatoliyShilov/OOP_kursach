#ifndef NPC_H
#define NPC_H
#include <actor.h>
#include "bag.h"

class NPC: public Actor//�������� ���
{
    int id;//���������
    char name[50];//���������
    bool isEnemy;//���������
    Bag bag;//���������
public:
    Bag getBag();
    NPC();
};

#endif // NPC_H
