#include "Room.h"

Room::Room() {
	// Инициализация матрицы иследованных ячеек.
	charLab.explored_way = new bool* [charLab.labyrinthWidth + 2];
	for (short i = 0; i < charLab.labyrinthWidth + 2; i++) {
		charLab.explored_way[i] = new bool[charLab.labyrinthHeight + 2];
		for (short j = 0; j < charLab.labyrinthHeight + 2; j++) {
			charLab.explored_way[i][j] = false;
		}
	}
}