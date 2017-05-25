#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H
#include "player.h"
#include "iostream"
#include "windows.h"
#include "additionfunction.h"

class AbstractController
{
protected:
    Player *player;
public:
    AbstractController();
    virtual int start() = 0;
    void setPayer(Player &player);
};

#endif // ABSTRACTCONTROLLER_H
