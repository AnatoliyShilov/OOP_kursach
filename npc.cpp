#include "npc.h"

NPC::NPC()
{
    id = 0;
}

NPCInfo NPC::getInfo()
{
    NPCInfo info;
    info.charsMax = charsMax;
    info.equip = equip;
    info.id = id;
    info.memoryFragments = memoryFragments;
    strcpy(info.name, name);
    return info;
}

void NPC::setInfo(NPCInfo info)
{
    charsMax = info.charsMax;
    equip = info.equip;
    id = info.id;
    memoryFragments = info.memoryFragments;
    strcpy(name, info.name);
    updateCharsCurrent();
}

