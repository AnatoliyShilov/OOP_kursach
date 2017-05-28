#include "traidecontroller.h"
template <class T>
Link<T> *TraideController::select(Link<T> *begDisp, bool forsell)
{
    if (!begDisp)
    {
        Menu::info("", "\t\t\tПусто");
        return NULL;
    }
    Link<T> *endDisp = begDisp;
    int key;
    int select = 0, count;
    const char *indicator[5];
    for (int i = 1; i < 5; i++)
        indicator[i] = "[]";
    ItemInfo info;
    while (true)
    {
        system("cls");
        endDisp = begDisp;
        indicator[select] = ">>";
        std::cout<<"\t\t\tВыберите предмет\n"
                   "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<<
                   "[]                     Название                     [] Прочность  []Стоимость []";
        count = 0;
        for (int i = 0; endDisp && i < 5; i++, count++)
        {
            info = endDisp->data.getInfo().item;
            std::cout<<indicator[i]<<" "<<setw(48)<<info.name<<" "<<indicator[i]<<" "<<setw(10)<<info.durability<<" "<<indicator[i]<<" ";
            if (forsell)
                std::cout<<setw(8)<<info.cost / 100<<" []";
            else
                std::cout<<setw(8)<<info.cost<<" []";
            endDisp = endDisp->Next;
        }
        count--;
        key = Menu::keyDecoder(getch());
        if (key == EXIT_CODE)
            return NULL;
        if (key == ENTER)
        {
            for (; select > 0; select--, begDisp = begDisp->Next);
            return begDisp;
        }
        indicator[select] = "[]";
        if (key == DOWN)
        {
            if ((select + 1 > count) && endDisp)
            {
                select = 0;
                begDisp = endDisp;
                continue;
            }
            if (select < count)
                select++;
            continue;
        }
        if (key == UP)
        {
            if ((select - 1 < 0) && begDisp->Prev)
            {
                select = 4;
                for (int i = 0; i <= 5 && begDisp->Prev; i++)
                    begDisp = begDisp->Prev;
                continue;
            }
            if (select > 0)
                select--;
        }
    }
}

void TraideController::accessories(Actor *seller)
{
    Link<Accessory> *ac;
    while (true)
    {
        ac = select(seller->openBag()->accessories.getBegin(), seller == player);
        if (!ac)
            return;
        if (seller == player)
        {
            player->addFragments(ac->data.getCost() / 100);
            player->openBag()->accessories.remove(ac);
        }
        else
        {
            if (player->getFragments() - ac->data.getCost() < 0)
            {
                Menu::info("","\t\t\tНедостаточно денег");
                return;
            }
            player->addFragments(-ac->data.getCost());
            player->add(ac->data);
        }
    }
}

void TraideController::armors(Actor *seller)
{
    Link<Armor> *ar;
    while (true)
    {
        ar = select(seller->openBag()->armors.getBegin(), seller == player);
        if (!ar)
            return;
        if (seller == player)
        {
            player->addFragments(ar->data.getCost() / 100);
            player->openBag()->armors.remove(ar);
        }
        else
        {
            if (player->getFragments() - ar->data.getCost() < 0)
            {
                Menu::info("","\t\t\tНедостаточно денег");
                return;
            }
            player->addFragments(-ar->data.getCost());
            player->add(ar->data);
        }
    }
}

void TraideController::weapons(Actor *seller)
{
    Link<Weapon> *w;
    while(true)
    {
        w = select(seller->openBag()->weapons.getBegin(), seller == player);
        if (!w)
            return;
        if (seller == player)
        {
            player->addFragments(w->data.getCost() / 100);
            player->openBag()->weapons.remove(w);
        }
        else
        {
            if (player->getFragments() - w->data.getCost() < 0)
            {
                Menu::info("","\t\t\tНедостаточно денег");
                return;
            }
            player->addFragments(-w->data.getCost());
            player->add(w->data);
        }
    }
}

void TraideController::setTraider(NPC *traider)
{
    this->traider = traider;
}

void TraideController::traide(const char *operation, Actor *seller)
{
    int result;
    const char *optNames[] =
    {
        "Аксессуары",
        "Доспехи",
        "Оружие",
        "Назад"
    };
    while (true)
    {
        result = Menu::displayVertical(operation, optNames, 4, NULL, NULL);
        if (result == EXIT_CODE || result == 3)
            return;
        (this->*traideOpt[result])(seller);
    }
}

int TraideController::start()
{
    int result;
    Actor *sellers[]
    {
        player,
        traider
    };
    const char *optNames[] =
    {
        "Продать",
        "Купить",
        "Выйти"
    };
    while (true)
    {
        result = Menu::displayVertical("Торговля", optNames, 3, NULL, NULL);
        if (result == EXIT_CODE || result == 2)
            return SUCCESS_CODE;
        traide(optNames[result], sellers[result]);
    }
    return SUCCESS_CODE;
}

TraideController::TraideController()
{
    traideOpt[0] = accessories;
    traideOpt[1] = armors;
    traideOpt[2] = weapons;
}
