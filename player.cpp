#include "player.h"

void Player::changeLvl(Chars dxChars, int dxLvl)
{
    if (!dxLvl)
        return;
    charsMax.health += dxChars.health;
    charsMax.stamina += dxChars.stamina;
    charsMax.strenght += dxChars.strenght;
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
     for (Link<Throwing> *thr = bag.throwings.getBegin(); thr; thr = thr->Next)
         if (charsCurrent.luck > Dice::roll())
            this->bag.throwings.add(thr->data);
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
