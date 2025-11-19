#include "Hero.h"

Hero::Hero() : heroX(2), heroY(2) {}

int Hero::hero_handler(Labirinth class_lab) {
    //class_lab.busyCoordLabyrint[heroX][heroY] = 4;
    //// Нажатие на "W".
    //if ((GetAsyncKeyState(0x57) & 0x8000) && class_lab.busyCoordLabyrint[heroX][heroY - 1]  == 1) {
    //    heroY--;
    //    return true;
    //}
    //// Нажатие на "S".
    //else if ((GetAsyncKeyState(0x53) & 0x8000) && class_lab.busyCoordLabyrint[heroX][heroY + 1] == 1) {
    //    heroY++;
    //    return true;
    //}
    //// Нажатие на "D".
    //else if ((GetAsyncKeyState(0x44) & 0x8000) && class_lab.busyCoordLabyrint[heroX + 1][heroY] == 1) {
    //    heroX++;
    //    return true;
    //}
    //// Нажатие на "A".
    //else if ((GetAsyncKeyState(0x41) & 0x8000) && class_lab.busyCoordLabyrint[heroX - 1][heroY] == 1) {
    //    heroX--;
    //    return true;
    //}
    return 1;
}
