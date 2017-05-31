#ifndef TRAIDECONTROLLER_H
#define TRAIDECONTROLLER_H
#include "abstractcontroller.h"
#include "npc.h"

class TraideController: public AbstractController//контроллер меню торговли
{
    void (TraideController::*traideOpt[3])(Actor *);//функции главного меню торговли
    NPC *traider;//указатель на торговца
    void accessories(Actor *seller);//продать/купить аксессуар
    void armors(Actor *seller);//продать/купить броню
    void weapons(Actor *seller);//продать/купить оружие
    template <class T>
    Link<T> *select(Link<T> *begDisp, bool forsell = false);//выбрать предмет для покупки/продажи
    void traide(const char *operation, Actor *seller);//меню покупки/продажи
public:
    TraideController();
    virtual int start();//запуск контроллера
    void setTraider(NPC *traider);//установить торговца
};

#endif // TRAIDECONTROLLER_H
