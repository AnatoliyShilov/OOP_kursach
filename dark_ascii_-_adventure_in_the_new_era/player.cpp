#include "player.h"

Player::Player()
{

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
