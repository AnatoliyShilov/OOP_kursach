#ifndef TRAIDECONTROLLER_H
#define TRAIDECONTROLLER_H
#include "abstractcontroller.h"

class TraideController: public AbstractController
{
public:
    TraideController();
    virtual int start();
};

#endif // TRAIDECONTROLLER_H
