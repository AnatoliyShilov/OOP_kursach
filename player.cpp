#include "player.h"

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
    out<<" # ";
    if (!bag.armors.isEmpty())
        for (Link<Armor>* temp = bag.armors.getBegin(); temp != NULL; temp = temp->Next)
            out<<temp->data.getId()<<" ";
    out<<" # ";
    if (!bag.weapons.isEmpty())
        for (Link<Weapon>* temp = bag.weapons.getBegin(); temp != NULL; temp = temp->Next)
            out<<temp->data.getId()<<" ";
    out<<" # ";
    out.close();
}

void Player::load(const char *file, AllItems allItems)
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
         if (!allItems.accessories.isEmpty())
            equip.accessory[i] = allItems.accessories.get(id - 1);
         else
            equip.accessory[i] = Accessory();
    }
    for (int i = 0; i < 4; i++)
    {
        in>>id;
        if (!allItems.armors.isEmpty())
            equip.armor[i] = allItems.armors.get(id - 1);
        else
            equip.armor[i] = Armor();
    }
    for (int i = 0; i < 2; i++)
    {
        in>>id;
        if (!allItems.weapons.isEmpty())
            equip.weapon[i] = allItems.weapons.get(id - 1);
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
        bag.accessories.add(allItems.accessories.get(id - 1));
    }
    buf[0] = '\0';
    while (true)
    {
        in>>buf;
        if (!strcmp(buf, "#"))
            break;
        id = atoi(buf);
        bag.armors.add(allItems.armors.get(id - 1));
    }
    buf[0] = '\0';
    while (true)
    {
        in>>buf;
        if (!strcmp(buf, "#"))
            break;
        id = atoi(buf);
        bag.weapons.add(allItems.weapons.get(id - 1));
    }
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

Armor Player::selectArmor(int id)
{
    Link<Armor> *temp = bag.armors.getBegin();
    for (; temp; temp = temp->Next)
        if (temp->data.getId() == id)
            return temp->data;
    Armor def;
    return def;
}

void Player::changeArmor(Armor armorNew, int index)
{
    if (armorNew.getType() != equip.armor[index].getType())
        return;
    bag.armors.add(equip.armor[index]);
    equip.armor[index] = armorNew;
}

Bag Player::openBag()
{
    return bag;
}

void Player::changeCoords(int dx, int dy)
{
    coords.changeCoords(dx, dy);
}
