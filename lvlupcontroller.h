#ifndef LVLUPCONTROLLER_H
#define LVLUPCONTROLLER_H
#include "abstractcontroller.h"

class LvlUPController: public AbstractController//контроллер повышения уровня и быстрого перемещения
{
    void (LvlUPController::*fMain[2])();//функции главного меню контроллера
    void lvlUPMenu();//меню повыщения уровня
    void fastTravelMenu();//меню быстрого перемещения
    int travelTo;//номер уровня пункта назначения
public:
    LvlUPController();
    virtual int start();//запуск контроллера
    int getTravelTo();//получить пункт назначения
};

#endif // LVLUPCONTROLLER_H
