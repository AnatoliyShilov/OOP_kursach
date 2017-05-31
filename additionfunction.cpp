#include "additionfunction.h"

void static Menu::logo()
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

int static Menu::displayVertical(const char* title, const char *nameOptions[], int count, void (*addInfo)(pVoid), pVoid arg)
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
    while (key != ENTER_KEY)
    {
        std::cout<<"\t\t"<<title<<"\n";
        if (addInfo != NULL)
            addInfo(arg);
        for (int i = 0; i < count; i++)
        {
            std::cout<<"\t\t";
            PrintFuncs::printSymbol('=', 9 + maxlen);
            std::cout<<"\n";
            std::cout<<"\t\t| "<<indicator[i]<<i+1<<" | "<<nameOptions[i]<<" |\n";
            std::cout<<"\t\t";
            PrintFuncs::printSymbol('=', 9 + maxlen);
            std::cout<<"\n";
        }
        std::cout<<"\t\t";
        key = getch();
        system("cls");
        indicator[current] = ' ';
        current = Menu::optionChangeVertical(key, current, count);
        indicator[current] = '>';
    }
    delete indicator;
    return current;
}


int static Menu::optionChangeVertical(int key, int current, int count)
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

int static Menu::keyDecoder(int key)
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
    if (key == 770 || key == 54 || key == 162 || key == 97)// * right (224/0 + 77) (54) (162) (97)
        return RIGHT;//R
    if (key == 750 || key == 52 || key == 228 || key == 100)// * left (224/0 + 75) (52) (228) (100)
        return LEFT;//L
    return ERROR_CODE;
}

int static Dice::roll(int upperBorder = 10000)
{
    srand(time(0));
    return rand()%(upperBorder + 1);
}

void static PrintFuncs::printSymbol(const char that, int count)
{
    for (int i = 0; i < count; i++, std::cout<<that);
}

int static PrintFuncs::strPrintLimit(const char* that, int howMany)
{
    for (int i = 0; i < howMany; i++)
    {
        if (that[i] == '\0')
            return howMany - i;
        std::cout<<that[i];
    }
    return 0;
}
