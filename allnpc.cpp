#include "allnpc.h"

NPC *AllNPC::getNPC(int id)
{
    for (Link<NPC> *temp = npcs.getBegin(); temp; temp = temp->Next)
        if (temp->data.getInfo().id == id)
            return &temp->data;
    return NULL;
}

////////////////////////////
void AllNPC::display()
{
    system("cls");
    std::cout<<"size "<<npcs.size()<<"\n";
    NPCInfo info;
    for (Link<NPC> *temp = npcs.getBegin(); temp; temp = temp->Next)
    {
        info = temp->data.getInfo();
        std::cout<<
                    info.id<<" "<<info.name<<"\n"<<
                    info.memoryFragments<<"\nЭкипировка\n\tАксессуары\n";
        for (int i = 0; i < 4; i++)
            if (info.equip.accessory[i].getId())
                std::cout<<"\t\t"<<info.equip.accessory[i].getInfo().item.name<<" "<<info.equip.accessory[i].getInfo().item.cost<<"\n";
            else
                std::cout<<"\t\tПусто\n";
        std::cout<<"\tБроня\n";
        for (int i = 0; i < 4; i++)
            if (info.equip.armor[i].getId())
                std::cout<<"\t\t"<<info.equip.armor[i].getInfo().item.name<<" "<<info.equip.armor[i].getInfo().item.cost<<"\n";
            else
                std::cout<<"\t\tПусто\n";
        std::cout<<"\tОружие\n";
        for (int i = 0; i < 2; i++)
            if (info.equip.weapon[i].getId())
                std::cout<<"\t\t"<<info.equip.weapon[i].getInfo().item.name<<" "<<info.equip.weapon[i].getInfo().item.cost<<"\n";
            else
                std::cout<<"\t\tПусто\n";
        std::cout<<"Инвентарь\n\tАксессуары\n";
        for (Link<Accessory> *ac = temp->data.openBag()->accessories.getBegin(); ac; ac = ac->Next)
            std::cout<<"\t\t"<<ac->data.getInfo().item.name<<" "<<ac->data.getInfo().item.cost<<"\n";
        std::cout<<"\tБроня\n";
        for (Link<Armor> *ar = temp->data.openBag()->armors.getBegin(); ar; ar = ar->Next)
            std::cout<<"\t\t"<<ar->data.getInfo().item.name<<" "<<ar->data.getInfo().item.cost<<"\n";
        std::cout<<"\tОружие\n";
        for (Link<Weapon> *w = temp->data.openBag()->weapons.getBegin(); w; w = w->Next)
            std::cout<<"\t\t"<<w->data.getInfo().item.name<<" "<<w->data.getInfo().item.cost<<"\n";
        system("pause");
    }
    system("pause");
}

///

void AllNPC::save(const char *file)
{
    ofstream out(file, ios::out);
    NPCInfo info;
    for (Link<NPC> *temp = npcs.getBegin(); temp; temp = temp->Next)
    {
        info = temp->data.getInfo();
        out<<
              info.id<<" "<<
              info.memoryFragments<<" "<<
              info.charsMax.health<<" "<<
              info.charsMax.stamina<<" "<<
              info.charsMax.regenS<<" "<<
              info.charsMax.strenght<<" "<<
              info.charsMax.carry<<" "<<
              info.charsMax.dexterity<<" "<<
              info.charsMax.luck<<" "<<
              info.name<<" #\n";
        for (int i = 0; i < 4; i++)
            out<<info.equip.accessory[i].getId()<<" ";
        out<<"\n";
        for (int i = 0; i < 4; i++)
            out<<info.equip.armor[i].getId()<<" ";
        out<<"\n";
        for (int i = 0; i < 2; i++)
            out<<info.equip.weapon[i].getId()<<" ";
        out<<"\n";
        if (!temp->data.openBag()->accessories.isEmpty())
            for (Link<Accessory>* ac = temp->data.openBag()->accessories.getBegin(); ac; ac = ac->Next)
                out<<ac->data.getId()<<" ";
        out<<" #\n";
        if (!temp->data.openBag()->armors.isEmpty())
            for (Link<Armor>* ar = temp->data.openBag()->armors.getBegin(); ar; ar = ar->Next)
                out<<ar->data.getId()<<" ";
        out<<" #\n";
        if (!temp->data.openBag()->weapons.isEmpty())
            for (Link<Weapon>* w = temp->data.openBag()->weapons.getBegin(); w; w = w->Next)
                out<<w->data.getId()<<" ";
        out<<" #\n";
    }
    out<<" ##\n";
    out.close();
}

int AllNPC::load(const char *file, AllItems *allItems)
{
    ifstream in(file, ios::in);
    if (!in.is_open())
    {
        in.close();
        Menu::info("Упс...", "Файл сохранений не может быть открыт.");
        return ERROR_CODE;
    }
    char buf[100];
    buf[0] = '\0';
    NPCInfo info;
    int id;
    while(true)
    {
        in>>buf;
        if (!strcmp(buf, "##"))
            break;
        info.id = atoi(buf);
        in>>
              info.memoryFragments>>
              info.charsMax.health>>
              info.charsMax.stamina>>
              info.charsMax.regenS>>
              info.charsMax.strenght>>
              info.charsMax.carry>>
              info.charsMax.dexterity>>
              info.charsMax.luck;
        in>>buf;
        strcpy(info.name, buf);
        while (true)
        {
            in>>buf;
            if (!strcmp(buf, "#"))
                break;
            strcat(info.name, " ");
            strcat(info.name, buf);
        }
        for (int i = 0; i < 4; i++)
        {
             in>>id;
             if (!allItems->accessories.isEmpty() && id)
                info.equip.accessory[i] = allItems->accessories.get(id - 1);
             else
                info.equip.accessory[i] = Accessory();
        }
        for (int i = 0; i < 4; i++)
        {
            in>>id;
            if (!allItems->armors.isEmpty() && id)
                info.equip.armor[i] = allItems->armors.get(id - 1);
            else
                info.equip.armor[i] = Armor();
        }
        for (int i = 0; i < 2; i++)
        {
            in>>id;
            if (!allItems->weapons.isEmpty() && id)
                info.equip.weapon[i] = allItems->weapons.get(id - 1);
            else
                info.equip.weapon[i] = Weapon();
        }
        id = 0;
        buf[0] = '\0';
        npcs.add(NPC());
        npcs.getEnd()->data.setInfo(info);
        while (true)
        {
            in>>buf;
            if (!strcmp(buf, "#"))
                break;
            id = atoi(buf);
            if (id > 0)
                npcs.getEnd()->data.add(allItems->accessories.get(id - 1));
        }
        buf[0] = '\0';
        while (true)
        {
            in>>buf;
            if (!strcmp(buf, "#"))
                break;
            id = atoi(buf);
            if (id > 0)
                npcs.getEnd()->data.add(allItems->armors.get(id - 1));
        }
        buf[0] = '\0';
        while (true)
        {
            in>>buf;
            if (!strcmp(buf, "#"))
                break;
            id = atoi(buf);
            if (id > 0)
                npcs.getEnd()->data.add(allItems->weapons.get(id - 1));
        }
    }
    in.close();
    return SUCCESS_CODE;
}

AllNPC::AllNPC()
{

}
