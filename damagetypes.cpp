#include "damagetypes.h"

void DamageTypes::setInfo(DamageTypesInfo info)
{
     this->bleeding = info.bleeding;
     this->crushing = info.crushing;
     this->cutting = info.cutting;
     this->general = info.general;
     this->poisoning = info.poisoning;
     this->pricking = info.pricking;
}

DamageTypesInfo DamageTypes::getInfo()
{
    DamageTypesInfo info;
    info.bleeding = this->bleeding;
    info.crushing = this->crushing;
    info.cutting = this->cutting;
    info.general = this->general;
    info.poisoning = this->poisoning;
    info.pricking = this->pricking;
    return info;
}

DamageTypes::DamageTypes()
{
    poisoning = bleeding = pricking = cutting = crushing = 0;
    general = 0;
}

DamageTypes::DamageTypes(int general, float pricking, float cutting, float crushing, float bleeding, float poisoning)
{
    this->general = general;
    this->pricking = pricking;
    this->cutting = cutting;
    this->crushing = crushing;
    this->bleeding = bleeding;
    this->poisoning = poisoning;
}

void DamageTypes::addToGeneral(int value)
{
    general += value;
}


int DamageTypes::getHealthDamage()
{
    return general +
            (int)(general * (1 + poisoning) +
                general * (1 + bleeding) +
                general * (1 + pricking) +
                general * (1 + cutting) +
                general * (1 + crushing));
}

void DamageTypes::setLessZero()
{
    if (poisoning < 0) poisoning = 0;
    if (bleeding < 0) bleeding = 0;
    if (pricking < 0) pricking = 0;
    if (cutting < 0) cutting = 0;
    if (crushing < 0) crushing = 0;
    if (general < 0) general = 0;
}

void DamageTypes::substract(DamageTypes damage)
{
    bleeding -= damage.bleeding;
    crushing -= damage.crushing;
    cutting -= damage.cutting;
    general -= damage.general;
    poisoning -= damage.poisoning;
    pricking -= damage.pricking;
    setLessZero();
}

void DamageTypes::add(DamageTypes damage)
{
    bleeding += damage.bleeding;
    crushing += damage.crushing;
    cutting += damage.cutting;
    general += damage.general;
    poisoning += damage.poisoning;
    pricking += damage.pricking;
}
