#ifndef ALLNPC_H
#define ALLNPC_H
#include <dynamic.h>
#include <npc.h>
using namespace std;
class AllNPC
{
    List <NPC> npcs;
public:
    AllNPC();
    NPC *getNPC(int id);
    void display();///////////////
    void save(const char *file);
    int load(const char *file, AllItems *allItems);
};

#endif // ALLNPC_H
