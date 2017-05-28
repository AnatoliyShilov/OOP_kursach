#ifndef TRAIDECONTROLLER_H
#define TRAIDECONTROLLER_H
#include "abstractcontroller.h"
#include "npc.h"

class TraideController: public AbstractController
{
    void (TraideController::*traideOpt[3])(Actor *);
    NPC *traider;
    void accessories(Actor *seller);
    void armors(Actor *seller);
    void weapons(Actor *seller);
    template <class T>
    Link<T> *select(Link<T> *begDisp, bool forsell = false);
    void traide(const char *operation, Actor *seller);
public:
    TraideController();
    virtual int start();
    void setTraider(NPC *traider);
};

#endif // TRAIDECONTROLLER_H
