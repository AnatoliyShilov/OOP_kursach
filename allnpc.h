#ifndef ALLNPC_H
#define ALLNPC_H
#include <dynamic.h>
#include <npc.h>
using namespace std;
class AllNPC//все НПС//хранит всех возможных НПС в игре
{
    List <NPC> npcs;//НПС
public:
    AllNPC();
    NPC *getNPC(int id);//получить указатель на НПС с номером id
    int getCount();//получить количество НПС
    void display();//Отобразить информацию о НПС, их экипировку и содержимое сумки
    void save(const char *file);//сохранить в файл
    int load(const char *file, AllItems *allItems);//загрузить из файла
};

#endif // ALLNPC_H
