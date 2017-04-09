#ifndef ADDITIONFUNCTION_H
#define ADDITIONFUNCTION_H
class Dice
{
public:
    int static roll(int upperBorder = 10000)
    {
        srand(time(0));
        return rand()%(upperBorder + 1);
    }
};
#endif // ADDITIONFUNCTION_H
