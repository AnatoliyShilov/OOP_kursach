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
    int nextLvlCost = player->getNextLvlCost(), dxLvl = 0;
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
                <<"\n\t���� ��������� ������\n"
                <<"\t������� ������������: "<<player->getFragments()<<"\n"
                <<"\t�������: "<<player->getFragments() - sum<<"\n"
                <<"\t��������� �������: "<<nextLvlCost<<"\n"
                <<"\t��������       "<<setw(4)<<chars[0]<<" -> "<<indicator[0][0]<<" "<<setw(4)<<chars[0] + dxChars[0] * 10<<" "<<indicator[0][1]<<"\n"
                <<"\t������������   "<<setw(4)<<chars[1]<<" -> "<<indicator[1][0]<<" "<<setw(4)<<chars[1] + dxChars[1] * 5<<" "<<indicator[1][1]<<"\n"
                <<"\t����           "<<setw(4)<<chars[2]<<" -> "<<indicator[2][0]<<" "<<setw(4)<<chars[2] + dxChars[2]<<" "<<indicator[2][1]<<"\n"
                <<"\t��������       "<<setw(4)<<chars[3]<<" -> "<<indicator[3][0]<<" "<<setw(4)<<chars[3] + dxChars[3]<<" "<<indicator[3][1]<<"\n"
                <<"\t\tENTER - �����������   BACKSPACE - ������\n";
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
        if (key == RIGHT && (sum + nextLvlCost <= player->getFragments()))
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
        nextLvlCost = player->getNextLvlCost();
        for (int i = 0; i < dxLvl; i++)
        {
            sum += nextLvlCost;
            nextLvlCost += nextLvlCost / 10;
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
    Menu::info("������� �������!", "�� ����� �������.");
}

int LvlUPController::getTravelTo()
{
    return travelTo;
}

void LvlUPController::fastTravelMenu()
{
    int key;
    while (true)
    {
        system("cls");
        std::cout
                <<"\t\t==========================\n"
                <<"\t\t|    �������� �������    |\n"
                <<"\t\t==========================\n"
                <<"\t\t|     ��������: "<<setw(3)<<player->getFastTravel()<<"      |\n"
                <<"\t\t==========================\n"
                <<"\t\t| < |      "<<setw(3)<<travelTo<<"       | > |\n"
                <<"\t\t==========================\n"
                  "\t\tENTER - �����������   BACKSPACE - ������\n";
        key = Menu::keyDecoder(getch());
        if (key == LEFT && travelTo > 0)
            travelTo -= 5;
        if (key == RIGHT && travelTo < player->getFastTravel())
            travelTo += 5;
        if (key == ENTER)
        {
            Menu::info("", "����������� ������ ������ ������������.");
            return;
        }
        if (key == EXIT_CODE)
            return;
    }
}

int LvlUPController::start()
{
    player->rest();
    travelTo = player->getFastTravel();
    Menu::info("�������� ��������.", "��������� ���� �������� ��� ��� � ����.");
    const char *optionsName[] =
    {
        "������� �����������",
        "�������� �������",
        "�����"
    };
    int result;
    result = Menu::displayVertical("������� ������", optionsName, 3, NULL, NULL);
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
