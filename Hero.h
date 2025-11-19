#pragma once
#include <iostream>
#include <windows.h>

#include "class_labyrint.h"
#include "cursor.h"
using namespace std;

class Hero
{
private: 
	// Координты персонажа.
	short heroX, heroY;
public:
	Hero();
	// Функция обрабатывающая нажатие WASD.
	int hero_handler(Labirinth class_lab);
};

