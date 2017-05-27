#ifndef ADDITIONFUNCTION_H
#define ADDITIONFUNCTION_H
#include "iostream"
#include "conio.h"
#include "string.h"
#include "cell.h"
#include "ctime"
#include <iomanip>
typedef void* pVoid;
//код завершения программы
#define EXIT_CODE -1
//код ошибки, во время выполнения функции возникли серьезные продлемы
#define ERROR_CODE -2
//код успешного завершения функции
#define SUCCESS_CODE -3
//код предупреждения, во время выполнения функции возникли незначительные проблемы
#define WARNING_CODE -4
//условное обозначение направления вверх
#define UP 8
//условное обозначение направления вниз
#define DOWN 2
//условное обозначение направления вправо
#define RIGHT 6
//условное обозначение направления влево
#define LEFT 4
//условное обозначение клавиши ENTER
#define ENTER 5
#define ENTER_KEY 13
//код клавиши ESCAPE
#define ESC_KEY 27
//код клавиши BACKSPACE
#define BACKSPACE_KEY 8
#define E_KEY 100
// * awsd, стрелки, стрелки нум-пада
// * up (56) (224/0 + 72) (230) (119)
// * down (50) (224/0 + 80) (235) (115)
// * enter 13
// * esc 27
// * right (224/0 + 77) (54) (162) (97)
// * left (224/0 + 75) (52) (228) (100)
// * backspace 8
class Sprites
{
public:
    const char *wall[3];
    const char *player[3];
    const char *wayin[3];
    const char *wayout[3];
    const char *door[3];
    const char *traider[3];
    const char *fire[3];
    const char *chest[3];
    virtual void init()
    {
        chest[0] = "/o\\";
        chest[1] = "|||";
        chest[2] = "===";
        fire[0] = " **";
        fire[1] = "** ";
        fire[2] = "/|\\";
        wall[0] = "XXX";
        wall[1] = "XXX";
        wall[2] = "XXX";
        player[0] = " o ";
        player[1] = "/|\\";
        player[2] = "/ \\";
        wayin[0] = " | ";
        wayin[1] = " | ";
        wayin[2] = "\\|/";
        wayout[0] = "/|\\";
        wayout[1] = " | ";
        wayout[2] = " | ";
        door[0] = "|||";
        door[1] = "||o";
        door[2] = "|||";
        traider[0] = "o/ ";
        traider[1] = "| T";
        traider[2] = "|\\|";
    }
};
class PrintFuncs
{
public:
    inline void static printSymbol(const char that, int count)
    {
        for (int i = 0; i < count; i++, std::cout<<that);
    }

    inline int static strPrintLimit(const char* that, int howMany)
    {
        int i = 0;
        for (; i < howMany; i++)
        {
            if (that[i] == '\0')
                break;
            std::cout<<that[i];
        }
        howMany -= i;
        printSymbol(' ', howMany);
        return 0;
    }

    void static printRoom(int currentlvl, Cell** cells, int roomSize, Coordinates Poss[3], Sprites s, int roomID)
    {
        system("cls");
        char **info = new char* [roomSize];
        char buf[5];
        for (int i = 0; i < roomSize; i++)
        {
            info[i] = new char [20];
            strcpy(info[i], "\0");
        }
        strcpy(info[0], "Уровень ");
        strcat(info[0], itoa(currentlvl, buf, 10));
        for (int i = 0; i < roomSize; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                std::cout<<"\t\t";
                for (int j = 0; j < roomSize; j++)
                {
                    switch (cells[i][j].getType())
                    {
                    case typeCell::WALL:
                    {
                        std::cout<<s.wall[k];
                        break;
                    }
                    case typeCell::WAYIN:
                    {
                        std::cout<<s.wayin[k];
                        break;
                    }
                    case typeCell::WAYOUT:
                    {
                        std::cout<<s.wayout[k];
                        break;
                    }
                    case typeCell::DOOR:
                    {
                        std::cout<<s.door[k];
                        break;
                    }
                    case typeCell::FLOOR:
                    case typeCell::TRAP:
                    {
                        std::cout<<"   ";
                        break;
                    }
                    }
                    if (Poss[1].getX() == j && Poss[1].getY() == i && !currentlvl)
                        std::cout<<char(8)<<char(8)<<char(8)<<s.traider[k];
                    if (Poss[2].getX() == j && Poss[2].getY() == i && !(currentlvl % 5) && !roomID)
                        std::cout<<char(8)<<char(8)<<char(8)<<s.fire[k];
                    if (Poss[0].getX() == j && Poss[0].getY() == i)
                        std::cout<<char(8)<<char(8)<<char(8)<<s.player[k];
                }
                if (k == 1)
                    std::cout<<"\t"<<info[i];
                std::cout<<"\n";
            }
        }
        for (int i = 0; i < roomSize; i++)
        {
            delete []info[i];
            delete []cells[i];
        }
    }
};

class Menu
{
public:
    void static logo()
    {
        system("cls");
        std::cout<<"\n\n"
              "                                                           //\\\\                 "
              "                \\=+                        +==#++#==@=\\    +==/            /+\\  "
              "               #==/                      /==#      \\=@     @=#             @==/ "
              "             /====                       \\==#       @\\    \\==/                  "
              "            #@/==@       /\\+/   /++\\      ===@/          /==+   /++/      /\\+/  "
              "          /=\\ /==#       @==  +=##==\\      #===#/        +==  #=+#==\\    /==#   "
              "         #@/  \\==+      /==\\\\@/  +==/       /@===#      /==\\@/  #==     \\==/   "
              "       /=#++++#==/      #=@@\\   /==+          /====/    #=@@\\   \\==\\    /==+    "
              "      #@/     #==      \\===/    @=@    @        #==#   \\===/    ==#     #==     "
              "    /=+       ==@      @=@     +==/   \\=/       \\==+   @=@     +==/    /==\\     "
              "   #=/       /==#     +==/    /==+\\#  @==/     /==#   +==/    /==+\\+   @=@/#\\    "
              "+@@@@@+   /#@@@@@@@\\  #@\\     /==#/  \\@/\\#==@@=@+/    @@\\     /==+/    @==\\     \n\n"
               ;
    }

    static bool askWindow(const char *title, const char *info)
    {
        char indicator[2];
        indicator[0] = ' ';
        indicator[1] = '>';
        int currentAns = 1;
        int key;
        while (true)
        {
            system("cls");
            std::cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            std::cout<<"\t\tX   "<<title<<"   X\n\n\t\tX   "<<info<<"   X\n\n\t\t   ";
            std::cout<<"( "<<indicator[0]<<") ДА\t( "<<indicator[1]<<") НЕТ   \n";
            std::cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\t";
            key = keyDecoder(getch());
            if (key == ENTER)
                return !currentAns;
            if (key == EXIT_CODE)
                return false;
            indicator[currentAns] = ' ';
            if (key == LEFT)
            {
                currentAns = 0;
            }
            if (key == RIGHT)
            {
                currentAns = 1;
            }
            indicator[currentAns] = '>';
        }
    }

    static void info(const char *title, const char *info)
    {
        system("cls");
        std::cout
                <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
                <<"\t\tX   "<<title<<"   X\n\n\t\tX   "<<info<<"   X\n\n"
                <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\t";
        system("pause");
    }

    inline int static displayVertical(const char* title, const char *nameOptions[], int count, void (*addInfo)(pVoid), pVoid arg)
    {
        int key, current = 0;
        char *indicator = new char [count];
        for (key = 0; key < count; key++)
            indicator[key]=' ';
        indicator[current] = '>';
        system("cls");
        int maxlen = 0, sub = 0;
        for (int i = 0; i < count; i++)
        {
            sub = strlen(nameOptions[i]);
            if (sub > maxlen)
                maxlen = sub;
        }
        sub = strlen(title);
        if (sub > maxlen)
            maxlen = sub;
        while (key != ENTER_KEY)
        {
            if (title != NULL)
            {
                std::cout<<"\t\t\t";
                PrintFuncs::printSymbol('=', 9 + maxlen);
                std::cout<<"\n\t\t\t|      ";
                PrintFuncs::strPrintLimit(title, maxlen);
                std::cout<<" |\n";
            }
            std::cout<<"\t\t\t";
            PrintFuncs::printSymbol('=', 9 + maxlen);
            std::cout<<"\n";
            if (addInfo != NULL)
                addInfo(arg);
            for (int i = 0; i < count; i++)
            {
                std::cout<<"\t\t\t";
                PrintFuncs::printSymbol('=', 9 + maxlen);
                std::cout<<"\n"
                        <<"\t\t\t| "<<indicator[i]<<i+1<<" | ";
                PrintFuncs::strPrintLimit(nameOptions[i], maxlen);
                std::cout<<" |\n"
                        <<"\t\t\t";
                PrintFuncs::printSymbol('=', 9 + maxlen);
                std::cout<<"\n";
            }
            std::cout<<"\t\t\t";
            key = getch();
            system("cls");
            indicator[current] = ' ';
            current = Menu::optionChangeVertical(key, current, count);
            if (current == EXIT_CODE)
                return EXIT_CODE;
            indicator[current] = '>';
        }
        delete indicator;
        return current;
    }

    inline int static optionChangeVertical(int key, int current, int count)
    {
        if ((key = Menu::keyDecoder(key)) == ERROR_CODE)
            return current;
        if (key == EXIT_CODE)
            return EXIT_CODE;
        if (key == UP)
        {
            current--;
            if (current < 0)
                current = count - 1;
        }
        else
            if (key == DOWN)
            {
                current++;
                if (current > count - 1)
                    current = 0;
            }
        return current;
    }

    inline int static keyDecoder(int key)
    {
        if (key == ESC_KEY || key == BACKSPACE_KEY)
            return EXIT_CODE;
        if (key == ENTER_KEY)
            return ENTER;//Enter
        if (key == 224 || key == 0)
            key = getch() * 10;
        if (key == 720 || key == 56 || key == 230 || key == 119)// * up (56) (224/0 + 72) (230) (119)
            return UP;//U
        if(key == 800 || key == 50 || key == 235 || key == 115)// * down (50) (224/0 + 80) (235) (115)
            return DOWN;//D
        if (key == 770 || key == 54 || key == 162 || key == 100)// * right (224/0 + 77) (54) (162) (97)
            return RIGHT;//R
        if (key == 750 || key == 52 || key == 228 || key == 97)// * left (224/0 + 75) (52) (228) (100)
            return LEFT;//L
        if (key == int('e') || key == int('E'))
            return E_KEY;
        return ERROR_CODE;
    }
};

class Dice
{
public:
    void static init()
    {
        srand(time(0));
    }

    int static random(int upperBorder = 10000)
    {
        return rand()%(upperBorder + 1);
    }

    int static roll(int upperBorder = 10000)
    {
        srand(time(0));
        return rand()%(upperBorder + 1);
    }
};

#endif // ADDITIONFUNCTION_H
