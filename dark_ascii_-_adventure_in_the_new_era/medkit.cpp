#include "medkit.h"

MedKit::MedKit()
{

}

int MedKit::useMedKit(){
    if (!count)
        return 0;
    count--;
    return effectivity;
}
