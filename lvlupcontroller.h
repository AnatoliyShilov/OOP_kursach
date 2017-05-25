#ifndef LVLUPCONTROLLER_H
#define LVLUPCONTROLLER_H
#include "abstractcontroller.h"

class LvlUPController: public AbstractController
{
    void (LvlUPController::*fMain[2])();
    void lvlUPMenu();
    void fastTravelMenu();
    int travelTo;
public:
    LvlUPController();
    virtual int start();
    int getTravelTo();
};

#endif // LVLUPCONTROLLER_H
