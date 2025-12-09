#pragma once
#include <string>
#include <vector>
using namespace std;

// Структура для ячеек под индесом 2.
struct cell {
	// Х, Y - координаты ячейки.
	// ParentX, ParentY - координаты родительской ячеки.
	cell(short X, short Y, short ParentX, short ParentY) :
		x(X), y(Y), parentX(ParentX), parentY(ParentY)
	{
	}
	short x, y,
		parentX, parentY;
	bool operator==(const cell& other) const {
		return x == other.x && y == other.y;
	}
};

extern cell cells;


// Структура, хранящая информацию о лабиринте.
struct characteristicsOfTheLabyrinth {
	// Ширина лабиринта вместе с границами.
	short labyrinthWidth = 39;
	// Высота лабиринта вместе с границами.
	short labyrinthHeight = 19;
	// Уровень сложность.
	string complexity = "Легко";

	// Координты персонажа.
	short heroX = 2, heroY = 2;

	// Количество попыток.
	short attempts = 0;

	// Матрица ислодованных ячеек.
	bool** explored_way;

	// Вектор ячеек под индексом 2.
	vector<cell> availableCoord;
	
	// Матрица индексов каждой ячейки.
	// 0 - к ячейке нет никакого доступа.
	// 1 - ячейка - проход в лабиринте (по ней можно передвигаться).
	// 2 - доступные для генерации ячейки (эта ячейка может стать проходом).
	// 3 - граница лабиринта.
	// 4 - позиция игрока.
	short** busyCoordLabyrint;

	// Последняя нажатая кнопка.
	// 1 - w.
	// 2 - a.
	// 3 - s.
	// 4 - d.
	short last_click_button = 0;

	// Количество телепортов.
	short count_teleport = 6;

	// Коичество взрывов.
	short count_boom = 6;

	// Выбранная способность.
	// 0 - без способности.
	// 1 - область видимости вокруг персонажа.
	// 2 - телепортация.
	// 3 - взрыв стен.
	short hero = 3;

	float rating[3] = { 100, 100, 100 };
};

extern characteristicsOfTheLabyrinth charLab;