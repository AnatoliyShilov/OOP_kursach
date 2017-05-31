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
    playerPos.setCoords(ROOM_SIZE / 2, ROOM_SIZE / 2);
}

void Controller::gameTick()
{
    int key;
    Coordinates Poss[4];
    Poss[1] = traiderPos;
    Poss[2] = firePos;
    Poss[3] = chestPos;
    Bag chest;
    int chestRoomId = 1;
    Dice::init();
    while (true)
    {

        Poss[0] = playerPos;
        PrintFuncs::printRoom(currentlvl,
                              lvl.getCurrentRoom().getCells(),
                              ROOM_SIZE,
                              Poss,
                              sprites,
                              lvl.getCurrentRoomID(),
                              chestRoomId);
        key = getch();
        key = Menu::keyDecoder(key);
        if (key == EXIT_CODE)
        {
            key = menuPause();
            if (key == EXIT_CODE)
                return;
        }
        if (key == UP && lvl.isFree(Coordinates(playerPos.getX(), playerPos.getY() - 1)))
            playerPos.changeCoords(0, -1);
        if (key == DOWN && lvl.isFree(Coordinates(playerPos.getX(), playerPos.getY() + 1)))
            playerPos.changeCoords(0, 1);
        if (key == LEFT && lvl.isFree(Coordinates(playerPos.getX() - 1, playerPos.getY())))
            playerPos.changeCoords(-1, 0);
        if (key == RIGHT && lvl.isFree(Coordinates(playerPos.getX() + 1, playerPos.getY())))
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
                if (playerPos.equals(firePos) &&
                        (lvl.getCurrentRoomID() == 0) &&
                        !(currentlvl % 5))
                {
                    player.save("pl.sav");
                    lvlUpMenu.start();
                    setCurrentLvl();
                    player.save("pl.sav");
                }
                else
                    if (playerPos.equals(chestPos) &&
                            (lvl.getCurrentRoomID() == chestRoomId))
                    {
                        if (!chest.accessories.isEmpty())
                        {
                            Menu::info("Осмотрев сундук вы получили:", chest.accessories.getBegin()->data.getInfo().item.name);
                            player.add(chest.accessories.getBegin()->data);
                            chest.accessories.removeAll();
                        }
                        else
                            if (!chest.armors.isEmpty())
                            {
                                Menu::info("Осмотрев сундук вы получили:", chest.armors.getBegin()->data.getInfo().item.name);
                                player.add(chest.armors.getBegin()->data);
                                chest.armors.removeAll();
                            }
                            else
                                if (!chest.weapons.isEmpty())
                                {
                                    Menu::info("Осмотрев сундук вы получили:", chest.weapons.getBegin()->data.getInfo().item.name);
                                    player.add(chest.weapons.getBegin()->data);
                                    chest.weapons.removeAll();
                                }
                    }
                    else
                        inventoryMenu.start();
        }
        switch (lvl.getTypeCell(Coordinates(playerPos.getX(), playerPos.getY())))
        {
        case WAYIN:
        {
            chestRoomId = Dice::random(23) + 1;
            switch (Dice::random(2))
            {
            case 0:
            {
                chest.accessories.add(allItems.accessories.get(Dice::random(allItems.accessories.size() - 1)));
                break;
            }
            case 1:
            {
                chest.armors.add(allItems.armors.get(Dice::random(allItems.armors.size() - 1)));
                break;
            }
            case 2:
            {
                chest.weapons.add(allItems.weapons.get(Dice::random(allItems.weapons.size() - 1)));
                break;
            }
            }
            currentlvl++;
            lvl.generateLvl(Coordinates(0, 0));
            playerPos.setCoords(ROOM_SIZE / 2, ROOM_SIZE / 2);
            if (!(currentlvl % 5))
                player.setFastTravel(currentlvl);
            break;
        }
        case WAYOUT:
        {
            currentlvl--;
            playerPos.setCoords(ROOM_SIZE / 2, ROOM_SIZE / 2);
            if (!currentlvl)
            {
                lvl.lvl0();
                break;
            }
            lvl.generateLvl(Coordinates(LVL_SIZE - 1, LVL_SIZE - 1));
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
                lvl.changeCurrentRoom(Coordinates(-1, 0));
                playerPos.changeCoords(0, ROOM_SIZE - 1);
                break;
            }
            if (playerPos.getY() == ROOM_SIZE - 1)
            {
                lvl.changeCurrentRoom(Coordinates(1, 0));
                playerPos.changeCoords(0, -ROOM_SIZE + 1);
                break;
            }
            if (playerPos.getX() == 0)
            {
                lvl.changeCurrentRoom(Coordinates(0, -1));
                playerPos.changeCoords(ROOM_SIZE - 1, 0);
                break;
            }
            if (playerPos.getX() == ROOM_SIZE - 1)
            {
                lvl.changeCurrentRoom(Coordinates(0, 1));
                playerPos.changeCoords(-ROOM_SIZE + 1, 0);
                break;
            }
            break;
        }
        default:break;
        }
        player.regenStamina();
        if (currentlvl && lvl.getCurrentRoomID())
            battleMenu.start();
        if (player.isDead())
        {
            player.addFragments(-player.getFragments());
            player.save("pl.sav");
            player.rest();
            lvl.lvl0();
            currentlvl = 0;
            playerPos.setCoords(ROOM_SIZE / 2, ROOM_SIZE / 2);
            Menu::dead();
        }
    }
}

void Controller::newGame()
{
    player.lvl0();
    player.save("pl.sav");
    playerPos.setCoords(ROOM_SIZE / 2, ROOM_SIZE / 2);
    lvl.lvl0();
    currentlvl = 0;
    if (!Menu::askWindow("Начать новую игру?", "Данное действие не обратимо!"))
        return;
    Controller::continueGame();
}

void Controller::continueGame()
{
    player.resetBattleChars();
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
            if (Menu::askWindow("Вы точно хотите выйти?", "Все несохраненные данные будут потеряны."))
                return EXIT_CODE;
            else
                continue;
        }
        (this->*fMain[result])();
    }
}

void Controller::Run()
{
    if (allItems.load("it.sav") == ERROR_CODE)
        return;
    if (allNPC.load("npc.sav", &allItems) == ERROR_CODE)
        return;
    traideMenu.setTraider(allNPC.getNPC(1));
    player.load("pl.sav", &allItems);
    Menu::logo();
    system("pause");
    menuMain();
}

Controller::~Controller()
{
    player.save("pl.sav");
    allItems.save("it.sav");
    allNPC.save("npc.sav");
}

Controller::Controller()
{
    //TODO ???
    sprites.init();
    playerPos.setCoords(ROOM_SIZE / 2, ROOM_SIZE / 2);
    firePos.setCoords(ROOM_SIZE / 2, ROOM_SIZE / 2);
    chestPos.setCoords(ROOM_SIZE / 2, ROOM_SIZE / 2);
    traiderPos.setCoords(7, 4);
    lvl.lvl0();
    currentlvl = 0;
    fMain[0] = Controller::continueGame;
    fMain[1] = Controller::newGame;
    traideMenu.setPayer(player);
    inventoryMenu.setPayer(player);
    lvlUpMenu.setPayer(player);
    battleMenu.setPayer(player);
    battleMenu.setNPCs(allNPC);
}
