#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H
#include "player.h"
#include "iostream"
#include "windows.h"
#include "additionfunction.h"

class AbstractController//абстрактный класс контроллер
{
protected:
    Player *player;//указатель на игрока для обработки и применения локальных изменений
public:
    AbstractController();
    virtual int start() = 0;//абстрактный метод запускающий контроллер
    void setPayer(Player &player);//подключить игрока к контроллеру
};

#endif // ABSTRACTCONTROLLER_H
