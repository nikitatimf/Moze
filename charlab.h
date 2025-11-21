#pragma once
#include <string>
using namespace std;

// Структура, хранящая информацию о лабиринте.
struct characteristicsOfTheLabyrinth {
	// Ширина лабиринта вместе с границами.
	short labyrinthWidth = 39;
	// Высота лабиринта вместе с границами.
	short labyrinthHeight = 19;
	// Уровень сложность.
	string complexity = "Легко";

	// Количество попыток.
	short attempts = 0;

	// Матрица ислодованных ячеек.
	bool** explored_way;
	
	// Матрица индексов каждой ячейки.
	// 0 - к ячейке нет никакого доступа.
	// 1 - ячейка - проход в лабиринте (по ней можно передвигаться).
	// 2 - доступные для генерации ячейки (эта ячейка может стать проходом).
	// 3 - граница лабиринта.
	// 4 - позиция игрока.
	short** busyCoordLabyrint;

};

extern characteristicsOfTheLabyrinth charLab;