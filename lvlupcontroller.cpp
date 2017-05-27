#include "lvlupcontroller.h"

void LvlUPController::lvlUPMenu()
{
    int chars[4], dxChars[4];
    for (int i = 0; i < 4; i++)
        dxChars[i] = 0;
    chars[0] = player->getMaxChars().health;
    chars[1] = player->getMaxChars().stamina;
    chars[2] = player->getMaxChars().strenght;
    chars[3] = player->getMaxChars().dexterity;
    PlayerInfo info = player->getInfo();
    int dxLvl = 0;
    int sum = 0, key, parametr = 0;
    char indicator[4][2];
    indicator[0][0] = '<';
    indicator[0][1] = '>';
    for (int i = 1; i < 4; i++)
        indicator[i][0] = indicator[i][1] = ' ';
    while(true)
    {
        system("cls");
        std::cout
                <<"\t\t\t[] Меню повышения уровня []\n"
                <<"\t\t[][][][][][][][][][][][][][][][][][][][]\n"
                <<"\t\t[] Осколки воспоминаний:  "<<setw(10)<<info.memoryFragments<<"  []\n"
                <<"\t\t[] Остаток:               "<<setw(10)<<info.memoryFragments - sum<<"  []\n"
                <<"\t\t[] Следующий уровень:     "<<setw(10)<<info.nextLvlCost<<"  []\n"
                <<"\t\t[][][][][][][][][][][][][][][][][][][][]\n"
                <<"\t\t[] Уровень        "<<setw(4)<<info.curentLvl<<" -> "<<setw(4)<<info.curentLvl + dxLvl<<"        []\n"
                <<"\t\t[] Здоровье       "<<setw(4)<<chars[0]<<" -> "<<indicator[0][0]<<" "<<setw(4)<<chars[0] + dxChars[0] * 10<<" "<<indicator[0][1]<<"    []\n"
                <<"\t\t[] Выносливость   "<<setw(4)<<chars[1]<<" -> "<<indicator[1][0]<<" "<<setw(4)<<chars[1] + dxChars[1] * 5<<" "<<indicator[1][1]<<"    []\n"
                <<"\t\t[] Сила           "<<setw(4)<<chars[2]<<" -> "<<indicator[2][0]<<" "<<setw(4)<<chars[2] + dxChars[2]<<" "<<indicator[2][1]<<"    []\n"
                <<"\t\t[] Ловкость       "<<setw(4)<<chars[3]<<" -> "<<indicator[3][0]<<" "<<setw(4)<<chars[3] + dxChars[3]<<" "<<indicator[3][1]<<"    []\n"
                <<"\t\t[][][][][][][][][][][][][][][][][][][][]\n"
                <<"\t\tENTER - подтвердить   BACKSPACE - отмена\n";
        key = Menu::keyDecoder(getch());
        indicator[parametr][0] = indicator[parametr][1] = ' ';
        if (key == DOWN)
        {
            parametr++;
            if (parametr > 3)
                parametr = 0;
        }
        if (key == UP)
        {
            parametr--;
            if (parametr < 0)
                parametr = 3;
        }
        indicator[parametr][0] = '<';
        indicator[parametr][1] = '>';
        if (key == RIGHT && (sum + info.nextLvlCost <= info.memoryFragments))
        {
            dxLvl++;
            dxChars[parametr]++;
        }
        if (key == LEFT && dxChars[parametr] > 0)
        {
            dxLvl--;
            dxChars[parametr]--;
        }
        sum = 0;
        info.nextLvlCost = player->getNextLvlCost();
        for (int i = 0; i < dxLvl; i++)
        {
            sum += info.nextLvlCost;
            info.nextLvlCost += info.nextLvlCost / 10;
        }
        if (key == ENTER)
            break;
        if (key == EXIT_CODE)
            return;
    }
    Chars charsDX;
    charsDX.health = dxChars[0] * 10;
    charsDX.stamina = dxChars[1] * 5;
    charsDX.strenght = dxChars[2];
    charsDX.dexterity = dxChars[3];
    player->changeLvl(charsDX, dxLvl);
    Menu::info("Уровень повышен!", "Вы стали сильнее.");
}

int LvlUPController::getTravelTo()
{
    return travelTo;
}

void LvlUPController::fastTravelMenu()
{
    int key;
    travelTo = player->getFastTravel();
    while (true)
    {
        system("cls");
        std::cout
                <<"\t\t==========================\n"
                <<"\t\t|    Выберите уровень    |\n"
                <<"\t\t==========================\n"
                <<"\t\t|     Прогресс: "<<setw(3)<<player->getFastTravel()<<"      |\n"
                <<"\t\t==========================\n"
                <<"\t\t| < |      "<<setw(3)<<travelTo<<"       | > |\n"
                <<"\t\t==========================\n"
                  "\t\tENTER - подтвердить   BACKSPACE - отмена\n";
        key = Menu::keyDecoder(getch());
        if (key == LEFT && travelTo > 0)
            travelTo -= 5;
        if (key == RIGHT && travelTo < player->getFastTravel())
            travelTo += 5;
        if (key == ENTER)
        {
            Menu::info("", "Перемещение сквозь пелену воспоминаний.");
            return;
        }
        if (key == EXIT_CODE)
            return;
    }
}

int LvlUPController::start()
{
    player->rest();
    Menu::info("Персонаж отдохнул.", "Неведомая сила укрепила ваш дух и тело.");
    const char *optionsName[] =
    {
        "Быстрое перемещение",
        "Повысить уровень",
        "Выйти"
    };
    int result;
    result = Menu::displayVertical("Главный костер", optionsName, 3, NULL, NULL);
    if (result == EXIT_CODE || result == 2)
        return EXIT_CODE;
    (this->*fMain[result])();
    return SUCCESS_CODE;
}

LvlUPController::LvlUPController()
{
    travelTo = 0;
    fMain[0] = LvlUPController::fastTravelMenu;
    fMain[1] = LvlUPController::lvlUPMenu;
}
