#ifndef INVENTORYCONTROLLER_H
#define INVENTORYCONTROLLER_H
#include "abstractcontroller.h"


class InventoryController: public AbstractController
{
public:
    InventoryController();
    virtual int start();
};

#endif // INVENTORYCONTROLLER_H
