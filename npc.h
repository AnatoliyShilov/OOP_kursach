#ifndef NPC_H
#define NPC_H
#include <actor.h>

struct NPCInfo
{
    int id;
    char name[50];
    int memoryFragments;
    Equipment equip;
    Chars charsMax;
};

class NPC: public Actor
{
    int id;
    char name[50];
public:
    NPC();
    NPCInfo getInfo();
    void setInfo(NPCInfo info);
};

#endif // NPC_H
