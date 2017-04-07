#include <iostream>
#include <windows.h>
#include "dynamic.h"
#include "accessory.h"
using namespace std;

int main(int argc, char *argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SetConsoleTitle(LPCWSTR("d"));//Dark ASCII - Adventure in the new era
    CONSOLE_FONT_INFOEX font;
    font.cbSize=sizeof(font);
    font.dwFontSize.X=14;
    font.dwFontSize.Y=14;
    font.FontWeight=FW_NORMAL;
    font.FontFamily=54;
    font.nFont=100;
    wcscpy(font.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &font);

    return 0;
}
