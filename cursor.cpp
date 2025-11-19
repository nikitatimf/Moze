#include "cursor.h"

// Функция для перемещения курсура в заданные координаты.
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursoreInfo;
    GetConsoleCursorInfo(hConsole, &cursoreInfo);
    cursoreInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursoreInfo);
    COORD position = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, position);
}