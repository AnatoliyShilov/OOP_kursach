#ifndef NPC_H
#define NPC_H
#include <actor.h>

struct NPCInfo//обертка информации о НПС
{
    int id;
    char name[50];
    int memoryFragments;
    Equipment equip;
    Chars charsMax;
};

class NPC: public Actor//НПС
{
    int id;//идентификатор
    char name[50];//имя
public:
    NPC();
    NPCInfo getInfo();//упаковать данные в обертку и вернуть ее
    void setInfo(NPCInfo info);// извлечь данные из обертки и установить их
};

#endif // NPC_H
