#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>

#include "cursor.h"
#include "Hero.h"
using namespace std;

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
	// Матрица индексов каждой ячейки.
	// 0 - к ячейке нет никакого доступа.
	// 1 - ячейка - проход в лабиринте (по ней можно передвигаться).
	// 2 - доступные для генерации ячейки (эта ячейка может стать проходом).
	// 3 - граница лабиринта.
	// 4 - позиция игрока.
	short** busyCoordLabyrint;

	Labirinth(short labyrintSizeX, short labyrintSizeY);

	// Функция, рисующая лабиринт.
	void print_labyrint();
	// Функция, генерирующая лабиринт.
	void generation_labyrint();
	// Функция, выводящая лабиринты по нажатию на Enter.
	void examples_of_labyrint();
	// Функция, показывающая принцип генерации лабиринта.
	void steps_of_generation_of_labyrint();
};

