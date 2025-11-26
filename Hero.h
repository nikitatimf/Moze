#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "cursor.h"
#include "charlab.h"
#include "main_menu.h"
using namespace std;

// Класс, содержащий функции, для работы с персонажем.
class Hero
{
private:
	// Функция, проверяющая, была ли отпущена клавиша WASD.
	// Если была отпущена - возвращается 0, иначе - 1.
	short was_passed_button();
	// Функция, выводящая меню при проигрыше.
	void lose_function();
	// Функция, выводящая меню при выйгрыше.
	void win_function();
public:
	// Функция обрабатывающая нажатие WASD.
	bool hero_handler();
};

