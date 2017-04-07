#include "medkit.h"

MedKit::MedKit()
{
    MedKit::count = 0;
    MedKit::countMax = 0;
    MedKit::effectivity = 0;
}

void MedKit::resetMedKitCount()
{
    count = countMax;
}

int MedKit::useMedKit(){
    if (!count)
        return 0;
    count--;
    return effectivity;
}
