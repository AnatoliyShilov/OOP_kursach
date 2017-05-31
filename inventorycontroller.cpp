#include "inventorycontroller.h"

int InventoryController::playerInfo(int key)
{
    PlayerInfo info = player->getInfo();
    std::cout<<"\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n"<<
               "\t[] Уровень               "<<setw(10)<<info.curentLvl<<"                     []\n"<<
               "\t[] Осколки воспоминаний  "<<setw(10)<<info.memoryFragments<<"                     []\n"<<
               "\t[] Следущий уровень      "<<setw(10)<<info.nextLvlCost<<"                     []\n"<<
               "\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n"<<
               "\t[] Здоровье                     "<<setw(10)<<info.charsMax.health<<" ( "<<setw(5)<<showpos<<info.charsCurrent.health - info.charsMax.health<<noshowpos<<" )    []\n"<<
               "\t[] Переносимый вес              "<<setw(10)<<info.charsMax.carry<<" ( "<<setw(5)<<showpos<<info.charsCurrent.carry - info.charsMax.carry<<noshowpos<<" )    []\n"<<
               "\t[] Выносливость                 "<<setw(10)<<info.charsMax.stamina<<" ( "<<setw(5)<<showpos<<info.charsCurrent.stamina - info.charsMax.stamina<<noshowpos<<" )    []\n"<<
               "\t[] Восстановление выносливости  "<<setw(10)<<info.charsMax.regenS<<" ( "<<setw(5)<<showpos<<info.charsCurrent.regenS - info.charsMax.regenS<<noshowpos<<" )    []\n"<<
               "\t[] Сила                         "<<setw(10)<<info.charsMax.strenght<<" ( "<<setw(5)<<showpos<<info.charsCurrent.strenght - info.charsMax.strenght<<noshowpos<<" )    []\n"<<
               "\t[] Ловкость                     "<<setw(10)<<info.charsMax.dexterity<<" ( "<<setw(5)<<showpos<<info.charsCurrent.dexterity - info.charsMax.dexterity<<noshowpos<<" )    []\n"<<
               "\t[] Удача                        "<<setw(10)<<info.charsMax.luck<<" ( "<<setw(5)<<showpos<<info.charsCurrent.luck - info.charsMax.luck<<noshowpos<<" )    []\n"<<
               "\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n"
               "\t+ Аптечки: "<<player->getMedKitCount()<<"\n";
    return key;
}

int InventoryController::equipments(int key)
{
    Equipment equip = player->getEquipment();
    char indicator[10][2];
    for (int i = 0 ; i < 10; i++)
        for (int j = 0; j < 2; j++)
            indicator[i][j] = ' ';
    indicator[key][0] = '<';
    indicator[key][1] = '>';
    std::cout<<"[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
               "   /----------------------\\                         |                           "<<
               "  |------------------------|======O  Оружие     O===|=================>         "<<
               "   \\----------------------/                         |                           \n";
    for (int i = 0; i < 2; i++, std::cout<<"\n")
        if (equip.weapon[i].getId())
            std::cout<<"\t"<<indicator[i][0]<<" "<<equip.weapon[i].getInfo().item.name<<" "<<indicator[i][1]<<
                       "   Прочность: "<<equip.weapon[i].getInfo().item.durability<<"\t";
        else
            std::cout<<"\t"<<indicator[i][0]<<" "<<"Пусто"<<" "<<indicator[i][1]<<"\t";
    std::cout<<"[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
               "           /===\\                                            /==\\                "<<
               "           | & |                     Броня                  |<>|                "<<
               "           \\ _ /                                            |==|               \n";
    key = 2;
    for (int i = 0; i < 4; i++, std::cout<<"\n")
        if (equip.armor[i].getId())
            std::cout<<"\t"<<indicator[i + key][0]<<" "<<equip.armor[i].getInfo().item.name<<" "<<indicator[i + key][1]<<
                       "   Прочность: "<<equip.armor[i].getInfo().item.durability<<"\t";
        else
            std::cout<<"\t"<<indicator[i + key][0]<<" "<<"Пусто"<<" "<<indicator[i + key][1]<<"\t";
    std::cout<<"[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
               "      /+\\                                                  __\\__                "<<
               "      +++                          Аксессуары                 \\                 "<<
               "      \\+/                                                      \\                 \n";
    key += 4;
    for (int i = 0; i < 4; i++, std::cout<<"\n")
        if (equip.accessory[i].getId())
            std::cout<<"\t"<<indicator[i + key][0]<<" "<<equip.accessory[i].getInfo().item.name<<" "<<indicator[i + key][1]<<
                       "   Прочность: "<<equip.accessory[i].getInfo().item.durability<<"\t";
        else
            std::cout<<"\t"<<indicator[i + key][0]<<" "<<"Пусто"<<" "<<indicator[i + key][1]<<"\t";
    std::cout<<"[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]";
    std::cout<<"\n";
    return key;
}

int InventoryController::accessories(int key)
{
    Link<Accessory> *accessories = player->openBag()->accessories.getBegin();
    if (accessories == NULL)
    {
        std::cout<<"\t\t\tПусто\n";
        return key;
    }
    AccessoryInfo info;
    for (int i = 0; i < key * 5; i++)
        accessories = accessories->Next;
    std::cout<<"[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
               "[]                     Название                     []       Прочность        []";
    for (int i = key * 5; i < player->openBag()->accessories.size() && i < key * 5 + 5; i++, accessories = accessories->Next)
    {
        info = accessories->data.getInfo();
        std::cout<<"[] "<<setw(48)<<info.item.name<<" [] "<<setw(22)<<info.item.durability<<" []";
    }
    return key;
}

int InventoryController::armors(int key)
{
    Link<Armor> *armors = player->openBag()->armors.getBegin();
    if (armors == NULL)
    {
        std::cout<<"\t\t\tПусто\n";
        return key;
    }
    ArmorInfo info;
    for (int i = 0; i < key * 5; i++)
        armors = armors->Next;
    std::cout<<"[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
               "[]                     Название                     [] Прочность  []   Вес    []";
    for (int i = key * 5; i < player->openBag()->armors.size() && i < key * 5 + 5; i++, armors = armors->Next)
    {
        info = armors->data.getInfo();
        std::cout<<"[] "<<setw(48)<<info.item.name<<" [] "<<setw(10)<<info.item.durability<<" [] "<<setw(8)<<info.weight<<" []";
    }
    return key;
}

int InventoryController::weapons(int key)
{
    Link<Weapon> *weapon = player->openBag()->weapons.getBegin();
    if (weapon == NULL)
    {
        std::cout<<"\t\t\tПусто\n";
        return key;
    }
    WeaponInfo info;
    for (int i = 0; i < key * 5; i++)
        weapon = weapon->Next;
    std::cout<<"[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
               "[]                     Название                     [] Прочность  []   Вес    []";
    for (int i = key * 5; i < player->openBag()->weapons.size() && i < key * 5 + 5; i++, weapon = weapon->Next)
    {
        info = weapon->data.getInfo();
        std::cout<<"[] "<<setw(48)<<info.item.name<<" [] "<<setw(10)<<info.item.durability<<" [] "<<setw(8)<<info.weight<<" []";
    }
    return key;
}

Armor InventoryController::selectArmor(ArmorType type)
{
    Link<Armor> *begDisp = player->openBag()->armors.getBegin();
    List<Armor> armorOfType;
    for (; begDisp; begDisp = begDisp->Next)
        if (begDisp->data.getType() == type)
            armorOfType.add(begDisp->data);
    begDisp = armorOfType.getBegin();
    Link<Armor> *endDisp = begDisp;
    int key;
    int select = 0, count;
    const char *indicator[5];
    for (int i = 1; i < 5; i++)
        indicator[i] = "[]";
    ArmorInfo info;
    while (true)
    {
        system("cls");
        endDisp = begDisp;
        indicator[select] = ">>";
        std::cout<<"\t\t\tВыберите экипировку\n"
                   "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
                   "[]                     Название                     [] Прочность  []   Вес    []";
        count = 0;
        for (int i = 0; endDisp != NULL && i < 5; i++, count++)
        {
            info = endDisp->data.getInfo();
            std::cout<<indicator[i]<<" "<<setw(48)<<info.item.name<<" "<<indicator[i]<<" "<<setw(10)<<info.item.durability<<" "<<indicator[i]<<" "<<setw(8)<<info.weight<<" []";
            endDisp = endDisp->Next;
        }
        count--;
        key = Menu::keyDecoder(getch());
        if (key == EXIT_CODE)
            return Armor();
        if (key == ENTER)
        {
            for (; select > 0; select--, begDisp = begDisp->Next);
            return begDisp->data;
        }
        indicator[select] = "[]";
        if (key == DOWN)
        {
            if (select + 1 > count && endDisp)
            {
                select = 0;
                begDisp = endDisp;
                continue;
            }
            if (select < count)
                select++;
        }
        if (key == UP)
        {
            if (select - 1 < 0 && begDisp->Prev != NULL)
            {
                select = 4;
                for (int i = 0; i <= 5 && begDisp->Prev != NULL; i++)
                    begDisp = begDisp->Prev;
                continue;
            }
            if (select > 0)
                select--;
        }
    }
}

Accessory InventoryController::selectAccessory()
{
    Link<Accessory> *begDisp = player->openBag()->accessories.getBegin();
    Link<Accessory> *endDisp = begDisp;
    int key;
    int select = 0, count;
    const char *indicator[5];
    for (int i = 1; i < 5; i++)
        indicator[i] = "[]";
    AccessoryInfo info;
    while (true)
    {
        system("cls");
        endDisp = begDisp;
        indicator[select] = ">>";
        std::cout<<"\t\t\tВыберите аксессуар\n"
                   "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
                   "[]                     Название                     []       Прочность        []";
        count = 0;
        for (int i = 0; endDisp && i < 5; i++, count++)
        {
            info = endDisp->data.getInfo();
            std::cout<<indicator[i]<<" "<<setw(48)<<info.item.name<<" "<<indicator[i]<<" "<<setw(22)<<info.item.durability<<" []";
            endDisp = endDisp->Next;
        }
        count--;
        key = Menu::keyDecoder(getch());
        if (key == EXIT_CODE)
            return Accessory();
        if (key == ENTER)
        {
            for (; select > 0; select--, begDisp = begDisp->Next);
            return begDisp->data;
        }
        indicator[select] = "[]";
        if (key == DOWN)
        {
            if ((select + 1 > count) && endDisp)
            {
                select = 0;
                begDisp = endDisp;
                continue;
            }
            if (select < count)
                select++;
            continue;
        }
        if (key == UP)
        {
            if ((select - 1 < 0) && begDisp->Prev)
            {
                select = 4;
                for (int i = 0; i <= 5 && begDisp->Prev; i++)
                    begDisp = begDisp->Prev;
                continue;
            }
            if (select > 0)
                select--;
        }
    }
}

Weapon InventoryController::selectWeapon()
{
    Link<Weapon> *begDisp = player->openBag()->weapons.getBegin();
    Link<Weapon> *endDisp = begDisp;
    int key;
    int select = 0, count;
    const char *indicator[5];
    for (int i = 1; i < 5; i++)
        indicator[i] = "[]";
    WeaponInfo info;
    while (true)
    {
        system("cls");
        endDisp = begDisp;
        indicator[select] = ">>";
        std::cout<<"\t\t\tВыберите оружие\n"
                   "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
                   "[]                     Название                     [] Прочность  []   Вес    []";
        count = 0;
        for (int i = 0; endDisp && i < 5; i++, count++)
        {
            info = endDisp->data.getInfo();
            std::cout<<indicator[i]<<" "<<setw(48)<<info.item.name<<" "<<indicator[i]<<" "<<setw(10)<<info.item.durability<<" "<<indicator[i]<<" "<<setw(8)<<info.weight<<" []";
            endDisp = endDisp->Next;
        }
        count--;
        key = Menu::keyDecoder(getch());
        if (key == EXIT_CODE)
            return Weapon();
        if (key == ENTER)
        {
            for (; select > 0; select--, begDisp = begDisp->Next);
            return begDisp->data;
        }
        indicator[select] = "[]";
        if (key == DOWN)
        {
            if ((select + 1 > count) && endDisp)
            {
                select = 0;
                begDisp = endDisp;
                continue;
            }
            if (select < count)
                select++;
            continue;
        }
        if (key == UP)
        {
            if ((select - 1 < 0) && begDisp->Prev)
            {
                select = 4;
                for (int i = 0; i <= 5 && begDisp->Prev; i++)
                    begDisp = begDisp->Prev;
                continue;
            }
            if (select > 0)
                select--;
        }
    }
}

int InventoryController::start()
{
    const char *menuName[5] =
    {
        "Персонаж",
        "Экипировка",
        "Оружие",
        "Доспехи",
        "Аксессуары"
    };
    char indicator[5];
    for (int i = 0; i < 5; i++)
        indicator[i] = ' ';
    int key = 0, tab = 0;
    indicator[tab] = '>';
    int select = 0;
    while (true)
    {
        player->sort();
        system("cls");
        std::cout<<"\t\t/  Инвентарь  \\\n";
        for (int i = 0; i < 5; i++)
            std::cout<<"[ ("<<indicator[i]<<")"<<menuName[i]<<" ]";
        std::cout<<"\n";
        key = (this->*options[tab])(select);

        key = Menu::keyDecoder(getch());
        if (key == EXIT_CODE)
            return SUCCESS_CODE;
        if (key == ENTER && tab == 1)
        {
            if (select < 2)
            {
                Weapon w = selectWeapon();
                if (w.getId())
                    player->changeWeapon(w, select);
                continue;
            }
            if (select < 6)
            {
                Armor ar = selectArmor(ArmorType(select - 2));
                if (ar.getId())
                    player->changeArmor(ar, select - 2);
                continue;
            }
            Accessory ac = selectAccessory();
            if (ac.getId())
                player->changeAccessory(ac, select - 6);
            continue;
        }
        if (key == E_KEY && tab == 1)
        {
            if (select < 2)
            {
                player->cleanWeapon(select);
                continue;
            }
            if (select < 6)
            {
                player->cleanArmor(select - 2);
                continue;
            }
            player->cleanAccessory(select - 6);
            continue;
        }
        if (key == DOWN)
        {
            if ((tab == 1 && select < 9) ||
                    (tab == 2 && (select + 1) * 5 < player->openBag()->weapons.size()) ||
                    (tab == 3 && (select + 1) * 5 < player->openBag()->armors.size()) ||
                    (tab == 4 && (select + 1) * 5 < player->openBag()->accessories.size()))
            {
                select++;
                continue;
            }
            continue;
        }
        if (key == UP)
        {
            if (select > 0)
                select--;
            continue;
        }
        indicator[tab] = ' ';
        if (key == RIGHT)
        {
            tab++;
            select = 0;
            if (tab > 4)
                tab = 0;
        }
        if (key == LEFT)
        {
            tab--;
            select = 0;
            if (tab < 0)
                tab = 4;
        }
        indicator[tab] = '>';
    }
    return SUCCESS_CODE;
}

InventoryController::InventoryController()
{
    options[0] = playerInfo;
    options[1] = equipments;
    options[2] = weapons;
    options[3] = armors;
    options[4] = accessories;
}
