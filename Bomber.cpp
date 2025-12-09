#include "Bomber.h"

void Bomber::boom() {
	// Если игрок израсходовал все попытки - выходим из функции.
	if (!charLab.count_boom) {
		return;
	}
	// Если нажата клавиша "Q".
	if (GetAsyncKeyState(0x51) & 0x8000) {
		if (!was_passed_button()) {
			// Если ячека не равна 3 - разрушение.
			// Сверху.
			if (charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY - 1] != 3) {
				// Именяем состояние ячейки тукущей позиции игрока на исслодованно.
				charLab.explored_way[charLab.heroX][charLab.heroY - 1] = true;
				// Изменяем состояние разрушенной ячейки на проход.
				charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY - 1] = 1;
				// Перекрашиваем ячейку прошлой позиции персонажа в цвет прохода.
				setCursorPosition(charLab.heroX - 1, charLab.heroY - 2);
				cout << "\033[0m";
				cout << " ";				
			}
			// Сверху справа.
			if (charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY - 1] != 3) {
				charLab.explored_way[charLab.heroX + 1][charLab.heroY - 1] = true;
				charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY - 1] = 1;
				setCursorPosition(charLab.heroX, charLab.heroY - 2);
				cout << "\033[0m";
				cout << " ";
			}
			// Справа.
			if (charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY] != 3) {
				charLab.explored_way[charLab.heroX + 1][charLab.heroY] = true;
				charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY] = 1;
				setCursorPosition(charLab.heroX, charLab.heroY - 1);
				cout << "\033[0m";
				cout << " ";
			}
			// Снизу справа.
			if (charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY + 1] != 3) {
				charLab.explored_way[charLab.heroX + 1][charLab.heroY + 1] = true;
				charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY + 1] = 1;
				setCursorPosition(charLab.heroX, charLab.heroY);
				cout << "\033[0m";
				cout << " ";
			}
			// Снизу.
			if (charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY + 1] != 3) {
				charLab.explored_way[charLab.heroX][charLab.heroY + 1] = true;
				charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY + 1] = 1;
				setCursorPosition(charLab.heroX - 1, charLab.heroY);
				cout << "\033[0m";
				cout << " ";
			}
			// Снизу слева.
			if (charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY + 1] != 3) {
				charLab.explored_way[charLab.heroX - 1][charLab.heroY + 1] = true;
				charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY + 1] = 1;
				setCursorPosition(charLab.heroX - 2, charLab.heroY);
				cout << "\033[0m";
				cout << " ";
			}
			// Слева.
			if (charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY] != 3) {
				charLab.explored_way[charLab.heroX - 1][charLab.heroY] = true;
				charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY] = 1;
				setCursorPosition(charLab.heroX - 2, charLab.heroY - 1);
				cout << "\033[0m";
				cout << " ";
			}
			// Сверху слева.
			if (charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY - 1] != 3) {
				charLab.explored_way[charLab.heroX - 1][charLab.heroY - 1] = true;
				charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY - 1] = 1;
				setCursorPosition(charLab.heroX - 2, charLab.heroY - 2);
				cout << "\033[0m";
				cout << " ";
			}

			charLab.count_boom--;
			fileEnd();
			// Обновляем количество взрывов.
			setCursorPosition(9, charLab.labyrinthHeight + 1);
			cout << "                              ";
			setCursorPosition(9, charLab.labyrinthHeight + 1);
			cout << "" << charLab.count_boom << " взрывов";

		}
	}
}
