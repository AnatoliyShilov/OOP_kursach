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
}

AccessoryType Accessory::getType()
{
    return accessoryType;
}

Chars Accessory::getCharsBonus()
{
    return additionChars;
}
