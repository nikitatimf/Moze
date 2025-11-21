#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>

#include "cursor.h"
#include "charlab.h"
using namespace std;

// Класс, для работы с лабиринтом.
class Labirinth
{
private:
	// Размер лабиринта вместе с границами.
	const short X, Y;

	// Размер матрицы busyCoordLabyrint.
	const short busyX, busyY;

	// Структура для ячеек под индесом 2.
	struct cell {
		// Х, Y - координаты ячейки.
		// ParentX, ParentY - координаты родительской ячеки.
		cell(short X, short Y, short ParentX, short ParentY) :
			x(X), y(Y), parentX(ParentX), parentY(ParentY) 
		{}
		short x, y,
			  parentX, parentY;
		bool operator==(const cell& other) const {
			return x == other.x && y == other.y;
		}
	};

	// Вектор ячеек под индексом 2.
	vector<cell> availableCoord;

	// Функция, добавляющая ячейки под индексом 2 в вектор.
	void addToAvailableCoord(cell p);

public:
	Labirinth();
	
	// Функция, рисующая лабиринт.
	void print_labyrint();
	// Функция, генерирующая лабиринт.
	void generation_labyrint();
	// Функция, выводящая лабиринты по нажатию на Enter.
	void examples_of_labyrint();
	// Функция, показывающая принцип генерации лабиринта.
	void steps_of_generation_of_labyrint();
};




