#include "medkit.h"

int MedKit::getCount()
{
    return count;
}

MedKit::MedKit()
{
    MedKit::count = 10;
    MedKit::countMax = 10;
    MedKit::effectivity = 3;
}

void MedKit::resetMedKitCount()
{
    count = countMax;
}

int MedKit::useMedKit(){
    count--;
    return effectivity;
}
