#include "controller.h"

void Controller::setCurrentLvl()
{
    if (currentlvl == lvlUpMenu.getTravelTo())
        return;
    currentlvl = lvlUpMenu.getTravelTo();
    if (currentlvl)
        lvl.generateLvl(Coordinates(0, 0));
    else
        lvl.lvl0();
    playerPos.setCoords(4, 4);
}

void Controller::gameTick()
{
    int key;
    Coordinates Poss[3];
    Poss[1] = traiderPos;
    Poss[2] = firePos;
    while (true)
    {
        Poss[0] = playerPos;
        PrintFuncs::printRoom(currentlvl,
                              lvl.getCurrentRoom().getCells(),
                              Poss,
                              sprites,
                              lvl.getCurrentRoomID());
        key = getch();
        key = Menu::keyDecoder(key);
        if (key == EXIT_CODE)
        {
            key = menuPause();
            if (key == EXIT_CODE)
                return;
        }
        if (key == UP && lvl.isFree(playerPos.getX(), playerPos.getY() - 1))
            playerPos.changeCoords(0, -1);
        if (key == DOWN && lvl.isFree(playerPos.getX(), playerPos.getY() + 1))
            playerPos.changeCoords(0, 1);
        if (key == LEFT && lvl.isFree(playerPos.getX() - 1, playerPos.getY()))
            playerPos.changeCoords(-1, 0);
        if (key == RIGHT && lvl.isFree(playerPos.getX() + 1, playerPos.getY()))
            playerPos.changeCoords(1, 0);
        if (key == E_KEY)
        {
            if (playerPos.equals(traiderPos) &&
                    (lvl.getCurrentRoomID() == 0) &&
                    !currentlvl)
            {
                traideMenu.start();
            }
            else
            {
                if (playerPos.equals(firePos) &&
                        (lvl.getCurrentRoomID() == 0) &&
                        !currentlvl)
                {
                    lvlUpMenu.start();
                    setCurrentLvl();
                }
                else
                {
                    inventoryMenu.start();
                }
            }
            //TODO
        }
        switch (lvl.getTypeCell(playerPos.getX(), playerPos.getY()))
        {
        case WAYIN:
        {
            currentlvl++;
            lvl.generateLvl(Coordinates(0, 0));
            playerPos.setCoords(4, 4);
            if (!(currentlvl % 5))
                player.setFastTravel(currentlvl);
            break;
        }
        case WAYOUT:
        {
            currentlvl--;
            playerPos.setCoords(4, 4);
            if (!currentlvl)
            {
                lvl.lvl0();
                break;
            }
            lvl.generateLvl(Coordinates(3, 3));
            break;
        }
        case TRAP:
        {
            break;
        }
        case DOOR:
        {
            if (playerPos.getY() == 0)
            {
                lvl.changeCurrentRoom(-1, 0);
                playerPos.changeCoords(0, 7);
                break;
            }
            if (playerPos.getY() == 7)
            {
                lvl.changeCurrentRoom(1, 0);
                playerPos.changeCoords(0, -7);
                break;
            }
            if (playerPos.getX() == 0)
            {
                lvl.changeCurrentRoom(0, -1);
                playerPos.changeCoords(7, 0);
                break;
            }
            if (playerPos.getX() == 7)
            {
                lvl.changeCurrentRoom(0, 1);
                playerPos.changeCoords(-7, 0);
                break;
            }
            break;
        }
        default:break;
        }
        //TODO
    }
    system("pause");
}

void Controller::newGame()
{
    if (!Menu::askWindow("Начать новую игру?", "Данное действие не обратимо!"))
        return;
    Controller::continueGame();
}

void Controller::continueGame()
{
    Controller::gameTick();
}

int Controller::menuPause()
{
    const char *optionsName[] =
    {
        "Продолжить",
        "Выйти в главное меню"
    };
    int result;
    result = Menu::displayVertical("Пауза", optionsName, 2, NULL, NULL);
    if (result)
        return EXIT_CODE;
    return SUCCESS_CODE;
}

int Controller::menuMain()
{
    const char *optionsName[] =
    {
        "Продолжить",
        "Новая игра",
        "Выйти"
    };
    int result;
    while (true)
    {
        result = Menu::displayVertical("Главное меню", optionsName, 3, NULL, NULL);
        if (result == EXIT_CODE || result == 2)
        {
            if (Menu::askWindow("Вы точно хотите выйти?", "Все не сохраненные данные будут потеряны."))
                return EXIT_CODE;
            else
                continue;
        }
        (this->*fMain[result])();
    }
}

void Controller::Run()
{
    Menu::logo();
    system("pause");
    menuMain();
}

Controller::Controller()
{
    //TODO ???
    sprites.init();
    playerPos.setCoords(4, 4);
    firePos.setCoords(4, 4);
    traiderPos.setCoords(6, 4);
    lvl.lvl0();
    player.lvl0();
    currentlvl = 0;
    fMain[0] = Controller::continueGame;
    fMain[1] = Controller::newGame;
    traideMenu.setPayer(player);
    inventoryMenu.setPayer(player);
    lvlUpMenu.setPayer(player);
}
