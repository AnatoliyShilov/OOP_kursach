#include "allitems.h"

void AllItems::save(const char *file)
{
    ofstream out(file, ios::out);
    if (!accessories.isEmpty())
    {
        AccessoryInfo accessory;
        for (Link<Accessory>* temp = accessories.getBegin(); temp != NULL; temp = temp->Next)
        {
            accessory = temp->data.getInfo();
            out<<accessory.accessoryType<<" "<<
                 accessory.additionChars.carry<<" "<<
                 accessory.additionChars.dexterity<<" "<<
                 accessory.additionChars.health<<" "<<
                 accessory.additionChars.luck<<" "<<
                 accessory.additionChars.regenS<<" "<<
                 accessory.additionChars.stamina<<" "<<
                 accessory.additionChars.strenght<<" "<<
                 accessory.item.damageT.bleeding<<" "<<
                 accessory.item.damageT.crushing<<" "<<
                 accessory.item.damageT.cutting<<" "<<
                 accessory.item.damageT.general<<" "<<
                 accessory.item.damageT.poisoning<<" "<<
                 accessory.item.damageT.pricking<<" "<<
                 accessory.item.durability<<" "<<
                 accessory.item.id<<" "<<
                 accessory.item.maxDurability<<" "<<
                 accessory.item.name;
            out<<" ##\n";
        }
    }
    out<<" # ";
    if (!armors.isEmpty())
    {
        ArmorInfo armor;
        for (Link<Armor>* temp = armors.getBegin(); temp != NULL; temp = temp->Next)
        {
            armor = temp->data.getInfo();
            out<<armor.type<<" "<<
                 armor.weight<<" "<<
                 armor.item.damageT.bleeding<<" "<<
                 armor.item.damageT.crushing<<" "<<
                 armor.item.damageT.cutting<<" "<<
                 armor.item.damageT.general<<" "<<
                 armor.item.damageT.poisoning<<" "<<
                 armor.item.damageT.pricking<<" "<<
                 armor.item.durability<<" "<<
                 armor.item.id<<" "<<
                 armor.item.maxDurability<<" "<<
                 armor.item.name;
            out<<" ##\n";
        }
    }
    out<<" # ";
    if (!weapons.isEmpty())
    {
        WeaponInfo weapon;
        for (Link<Weapon>* temp = weapons.getBegin(); temp != NULL; temp = temp->Next)
        {
            weapon = temp->data.getInfo();
            out<<weapon.weaponType<<" "<<
                 weapon.weight<<" "<<
                 weapon.item.damageT.bleeding<<" "<<
                 weapon.item.damageT.crushing<<" "<<
                 weapon.item.damageT.cutting<<" "<<
                 weapon.item.damageT.general<<" "<<
                 weapon.item.damageT.poisoning<<" "<<
                 weapon.item.damageT.pricking<<" "<<
                 weapon.item.durability<<" "<<
                 weapon.item.id<<" "<<
                 weapon.item.maxDurability<<" "<<
                 weapon.item.name;
            out<<" ##\n";
        }
    }
    out<<" # ";
    out.close();
}

int AllItems::load(const char *file)
{
    ifstream in(file, ios::in);
    if (!in.is_open())
    {
        in.close();
        Menu::info("”пс...", "‘айл игры поврежден.");
        return ERROR_CODE;
    }
    AccessoryInfo acInfo;
    ArmorInfo arInfo;
    WeaponInfo wInfo;
    Accessory ac;
    Armor ar;
    Weapon w;
    char buf[100];
    buf[0] = '\0';
    while (true)
    {
        in>>buf;
        if (!strcmp(buf, "#"))
            break;
        acInfo.accessoryType = AccessoryType(atoi(buf));
        in>>acInfo.additionChars.carry>>
             acInfo.additionChars.dexterity>>
             acInfo.additionChars.health>>
             acInfo.additionChars.luck>>
             acInfo.additionChars.regenS>>
             acInfo.additionChars.stamina>>
             acInfo.additionChars.strenght>>
             acInfo.item.damageT.bleeding>>
             acInfo.item.damageT.crushing>>
             acInfo.item.damageT.cutting>>
             acInfo.item.damageT.general>>
             acInfo.item.damageT.poisoning>>
             acInfo.item.damageT.pricking>>
             acInfo.item.durability>>
             acInfo.item.id>>
             acInfo.item.maxDurability;
        in>>buf;
        strcpy(acInfo.item.name, buf);
        while (true)
        {
            in>>buf;
            if (!strcmp(buf, "##"))
                break;
            strcat(acInfo.item.name, " ");
            strcat(acInfo.item.name, buf);
        }
        ac.setInfo(acInfo);
        accessories.add(ac);
    }
    buf[0] = '\0';
    while (true)
    {
        in>>buf;
        if (!strcmp(buf, "#"))
            break;
        arInfo.type = ArmorType(atoi(buf));
        in>>arInfo.weight>>
             arInfo.item.damageT.bleeding>>
             arInfo.item.damageT.crushing>>
             arInfo.item.damageT.cutting>>
             arInfo.item.damageT.general>>
             arInfo.item.damageT.poisoning>>
             arInfo.item.damageT.pricking>>
             arInfo.item.durability>>
             arInfo.item.id>>
             arInfo.item.maxDurability;
        in>>buf;
        strcpy(arInfo.item.name, buf);
        while (true)
        {
            in>>buf;
            if (!strcmp(buf, "##"))
                break;
            strcat(arInfo.item.name, " ");
            strcat(arInfo.item.name, buf);
        }
        ar.setInfo(arInfo);
        armors.add(ar);
    }
    buf[0] = '\0';
    while (true)
    {
        in>>buf;
        if (!strcmp(buf, "#"))
            break;
        wInfo.weaponType = WeaponType(atoi(buf));
        in>>wInfo.weight>>
             wInfo.item.damageT.bleeding>>
             wInfo.item.damageT.crushing>>
             wInfo.item.damageT.cutting>>
             wInfo.item.damageT.general>>
             wInfo.item.damageT.poisoning>>
             wInfo.item.damageT.pricking>>
             wInfo.item.durability>>
             wInfo.item.id>>
             wInfo.item.maxDurability;
        in>>buf;
        strcpy(wInfo.item.name, buf);
        while (true)
        {
            in>>buf;
            if (!strcmp(buf, "##"))
                break;
            strcat(wInfo.item.name, " ");
            strcat(wInfo.item.name, buf);
        }
        w.setInfo(wInfo);
        weapons.add(w);
    }
    in.close();
    return SUCCESS_CODE;
}

AllItems::AllItems()
{

}
