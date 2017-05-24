#include "accessory.h"

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
