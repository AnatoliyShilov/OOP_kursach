#include "player.h"

void Player::sort()
{
    if (bag.accessories.isEmpty() || bag.armors.isEmpty() || bag.weapons.isEmpty())
        return;
    Link<Accessory> *acS;
    Link<Armor> *arS;
    Link<Weapon> *wS;
    acS = bag.accessories.getBegin();
    arS = bag.armors.getBegin();
    wS = bag.weapons.getBegin();
    for (; acS->Next; acS = acS->Next)
        for (Link<Accessory> *temp = acS; temp; temp = temp->Next)
            if (temp->data.getId() < acS->data.getId())
                List<Accessory>::swap(acS, temp);
    for (; arS->Next; arS = arS->Next)
        for (Link<Armor> *temp = arS; temp; temp = temp->Next)
            if (temp->data.getId() < arS->data.getId())
                List<Armor>::swap(arS, temp);
    for (; wS->Next; wS = wS->Next)
        for (Link<Weapon> *temp = wS; temp; temp = temp->Next)
            if (temp->data.getId() < wS->data.getId())
                List<Weapon>::swap(wS, temp);
}

PlayerInfo Player::getInfo()
{
    PlayerInfo info;
    info.nextLvlCost = this->nextLvlCost;
    info.memoryFragments = this->memoryFragments;
    info.maxFastTravelId = this->maxFastTravelId;
    info.curentLvl = this->curentLvl;
    info.charsMax = this->charsMax;
    info.charsCurrent = this->charsCurrent;
    return info;
}

void Player::save(const char *file)
{
    ofstream out(file, ios::out);
    out<<memoryFragments<<"\n"<<

         charsMax.health<<" "<<
         charsMax.stamina<<" "<<
         charsMax.strenght<<" "<<
         charsMax.dexterity<<" "<<
         charsMax.carry<<" "<<
         charsMax.luck<<" "<<
         charsMax.regenS<<"\n"<<

         curentLvl<<" "<<
         nextLvlCost<<" "<<
         maxFastTravelId<<"\n";
    for (int i = 0; i < 4; i++)
         out<<equip.accessory[i].getId()<<" ";
    out<<"\n";
    for (int i = 0; i < 4; i++)
        out<<equip.armor[i].getId()<<" ";
    out<<"\n";
    for (int i = 0; i < 2; i++)
        out<<equip.weapon[i].getId()<<" ";
    out<<"\n";
    if (!bag.accessories.isEmpty())
        for (Link<Accessory>* temp = bag.accessories.getBegin(); temp != NULL; temp = temp->Next)
            out<<temp->data.getId()<<" ";
    out<<"#\n";
    if (!bag.armors.isEmpty())
        for (Link<Armor>* temp = bag.armors.getBegin(); temp != NULL; temp = temp->Next)
            out<<temp->data.getId()<<" ";
    out<<"#\n";
    if (!bag.weapons.isEmpty())
        for (Link<Weapon>* temp = bag.weapons.getBegin(); temp != NULL; temp = temp->Next)
            out<<temp->data.getId()<<" ";
    out<<"#\n";
    out.close();
}

void Player::load(const char *file, AllItems *allItems)
{
    ifstream in(file, ios::in);
    if (!in.is_open())
    {
        in.close();
        Menu::info("”пс...", "‘айл сохранений не может быть открыт.");
        Player::lvl0();
        save(file);
        return;
    }
    in>>memoryFragments>>

         charsMax.health>>
         charsMax.stamina>>
         charsMax.strenght>>
         charsMax.dexterity>>
         charsMax.carry>>
         charsMax.luck>>
         charsMax.regenS>>

         curentLvl>>
         nextLvlCost>>
         maxFastTravelId;
    int id;
    for (int i = 0; i < 4; i++)
    {
         in>>id;
         if (!allItems->accessories.isEmpty() && id)
            equip.accessory[i] = allItems->accessories.get(id - 1);
         else
            equip.accessory[i] = Accessory();
    }
    for (int i = 0; i < 4; i++)
    {
        in>>id;
        if (!allItems->armors.isEmpty() && id)
            equip.armor[i] = allItems->armors.get(id - 1);
        else
            equip.armor[i] = Armor();
    }
    for (int i = 0; i < 2; i++)
    {
        in>>id;
        if (!allItems->weapons.isEmpty() && id)
            equip.weapon[i] = allItems->weapons.get(id - 1);
        else
            equip.weapon[i] = Weapon();
    }
    id = 0;
    char buf[10];
    buf[0] = '\0';
    while (true)
    {
        in>>buf;
        if (!strcmp(buf, "#"))
            break;
        id = atoi(buf);
        if (id > 0)
            bag.accessories.add(allItems->accessories.get(id - 1));
    }
    buf[0] = '\0';
    while (true)
    {
        in>>buf;
        if (!strcmp(buf, "#"))
            break;
        id = atoi(buf);
        if (id > 0)
            bag.armors.add(allItems->armors.get(id - 1));
    }
    buf[0] = '\0';
    while (true)
    {
        in>>buf;
        if (!strcmp(buf, "#"))
            break;
        id = atoi(buf);
        if (id > 0)
            bag.weapons.add(allItems->weapons.get(id - 1));
    }
    updateCharsCurrent();
}

void Player::changeLvl(Chars dxChars, int dxLvl)
{
    if (!dxLvl)
        return;
    charsMax.health += dxChars.health;
    charsMax.stamina += dxChars.stamina;
    charsMax.regenS = charsMax.stamina / 10;
    charsMax.strenght += dxChars.strenght;
    charsMax.carry = charsMax.strenght * 2;
    charsMax.dexterity += dxChars.dexterity;
    curentLvl += dxLvl;
    int sum = 0;
    for (; dxLvl > 0; dxLvl--)
    {
        sum += nextLvlCost;
        nextLvlCost += nextLvlCost / 10;
    }
    memoryFragments -= sum;
    updateCharsCurrent();
}

int Player::getNextLvlCost()
{
    return nextLvlCost;
}

int Player::getFastTravel()
{
   return maxFastTravelId;
}

void Player::setFastTravel(int lvlId)
{
    maxFastTravelId = lvlId;
}

void Player::lvl0()
{
    curentLvl = 0;
    nextLvlCost = 100;
    maxFastTravelId = 0;
    memoryFragments = 0;
    Actor::lvl0();
}

void Player::rest()
{
    updateCharsCurrent();
    regenDurability();
}

Player::Player()
{

}

void Player::loot(Bag bag)
{
    for (Link<Accessory> *acc = bag.accessories.getBegin(); acc; acc = acc->Next)
        if (charsCurrent.luck > Dice::roll())
            this->bag.accessories.add(acc->data);
    for (Link<Weapon> *wea = bag.weapons.getBegin(); wea; wea = wea->Next)
        if (charsCurrent.luck > Dice::roll())
            this->bag.weapons.add(wea->data);
    for (Link<Armor> *arm = bag.armors.getBegin(); arm; arm = arm->Next)
        if (charsCurrent.luck > Dice::roll())
            this->bag.armors.add(arm->data);
}

void Player::cleanArmor(int index)
{
    if (!equip.armor[index].getId())
        return;
    bag.armors.add(equip.armor[index]);
    equip.armor[index] = Armor();
    updateCharsCurrent();
}

void Player::cleanWeapon(int index)
{
    if (!equip.weapon[index].getId())
        return;
    bag.weapons.add(equip.weapon[index]);
    equip.weapon[index] = Weapon();
    updateCharsCurrent();
}

void Player::cleanAccessory(int index)
{
    if (!equip.accessory[index].getId())
        return;
    bag.accessories.add(equip.accessory[index]);
    equip.accessory[index] = Accessory();
    updateCharsCurrent();
}

void Player::changeWeapon(Weapon weaponNew, int index)
{
    if (equip.weapon[index].getId())
        bag.weapons.add(equip.weapon[index]);
    int i = 0;
    for (Link<Weapon> *temp = bag.weapons.getBegin(); temp != NULL; temp = temp->Next, i++)
        if (weaponNew.getId() == temp->data.getId())
        {
            bag.weapons.remove(temp);
            break;
        }
    equip.weapon[index] = weaponNew;
    updateCharsCurrent();
}

void Player::changeAccessory(Accessory acessoryNew, int index)
{
    if (equip.accessory[index].getId())
        bag.accessories.add(equip.accessory[index]);
    int i = 0;
    for (Link<Accessory> *temp = bag.accessories.getBegin(); temp != NULL; temp = temp->Next, i++)
        if (acessoryNew.getId() == temp->data.getId())
        {
            bag.accessories.remove(temp);
            break;
        }
    equip.accessory[index] = acessoryNew;
    updateCharsCurrent();
}

void Player::changeArmor(Armor armorNew, int index)
{
    if (armorNew.getType() != ArmorType(index))
        return;
    if (equip.armor[index].getId())
        bag.armors.add(equip.armor[index]);
    int i = 0;
    for (Link<Armor> *temp = bag.armors.getBegin(); temp != NULL; temp = temp->Next, i++)
        if (armorNew.getId() == temp->data.getId())
        {
            bag.armors.remove(temp);
            break;
        }
    equip.armor[index] = armorNew;
    updateCharsCurrent();
}

Bag* Player::openBag()
{
    return &bag;
}
