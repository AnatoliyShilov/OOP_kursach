#include "accessory.h"

void Accessory::setInfo(AccessoryInfo info)
{
    this->accessoryType = info.accessoryType;
    this->additionChars = info.additionChars;
    Item::setInfo(info.item);
}

AccessoryInfo Accessory::getInfo()
{
    AccessoryInfo info;
    info.accessoryType = this->accessoryType;
    info.additionChars = this->additionChars;
    info.item = Item::getInfo();
    return info;
}

Accessory::Accessory()
{
    Accessory::accessoryType = AccessoryType::defence;
    additionChars.carry =
            additionChars.dexterity =
            additionChars.health =
            additionChars.luck =
            additionChars.regenS =
            additionChars.stamina =
            additionChars.strenght = 0;
}

AccessoryType Accessory::getType()
{
    return accessoryType;
}

Chars Accessory::getCharsBonus()
{
    return additionChars;
}
