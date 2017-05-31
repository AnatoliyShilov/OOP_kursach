#ifndef MEDKIT_H
#define MEDKIT_H


class MedKit//аптечки
{
    int count;//текущее количество
    int countMax;//максимальное количество
    int effectivity;//эффективность лечения
public:
    MedKit();
    void resetMedKitCount();//сбросить количество аптечек//текущее количество = максимальному
    int useMedKit();//использовать 1 аптечку и вернуть эффективность
    int getCount();//вернуть текущее количество аптечек
};

#endif // MEDKIT_H
