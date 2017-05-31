#include <iostream>
#include <windows.h>
#include "controller.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SetConsoleTitle(L"Dark ASCII");//Dark ASCII - Adventure in the new era
    system ("mode con cols=80 lines=35");
    CONSOLE_FONT_INFOEX font;
    font.cbSize=sizeof(font);
    font.dwFontSize.X=14;
    font.dwFontSize.Y=14;
    font.FontWeight=FW_NORMAL;
    font.FontFamily=54;
    font.nFont=100;
    wcscpy(font.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &font);

    Controller controller;
    controller.Run();

    return 0;
}
