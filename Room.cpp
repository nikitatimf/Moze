#include "Room.h"

Room::Room() : 
	explorSizeX(charLab.labyrinthWidth), explorSizeY(charLab.labyrinthHeight) 
{
	// Заполнение false во все ячейки матрицы иследованных путей кроме границ.
	charLab.explored_way = new bool* [explorSizeX];
	for (short x = 0; x < explorSizeX; x++) {
		charLab.explored_way[x] = new bool[explorSizeY];
		for (short y = 0; y < explorSizeY; y++) {
			if (x == 0 || x == explorSizeX - 1 ||
				y == 0 || y == explorSizeY - 1) {
				charLab.explored_way[x][y] = true;
				continue;
			}
			charLab.explored_way[x][y] = false;
		}
	}
}