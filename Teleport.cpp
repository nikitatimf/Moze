#include "Teleport.h"

void Teleport::teleport() {
	// Если не осталось попыток телепорта - выходим из функции.
	if (!charLab.count_teleport) {
		return;
	}
	bool isClick = false;
	// Нажатие на "W".
	// Если была нажата клавиша, и ячека, в которую игрок собирается телепортироваться - телепортация.
	if ((GetAsyncKeyState(0x57) & 0x8000) && 
		(GetAsyncKeyState(0x51) & 0x8000) &&
		charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY - 2] == 1) {
		if (!was_passed_button()) {
			// Изменяем индекс ячейки текущей позиции персонажа на 1.
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY] = 1;
			// Именяем состояние ячейки тукущей позиции игрока на исслодованно.
			charLab.explored_way[charLab.heroX][charLab.heroY] = true;
			// Изменяем индекс ячейки в которую перемещается персонаж на 4.
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY - 2] = 4;
			charLab.attempts--;
			// Перекрашиваем ячейку прошлой позиции персонажа в цвет прохода.
			setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
			cout << "\033[0m";
			cout << " ";
			charLab.heroY -= 2;
			charLab.last_click_button = 1;
			isClick = true;
		}
	}
	// Нажатие на "S".
	else if ((GetAsyncKeyState(0x53) & 0x8000) &&
		(GetAsyncKeyState(0x51) & 0x8000) && 
		charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY + 2] == 1) {
		if (!was_passed_button()) {
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY] = 1;
			charLab.explored_way[charLab.heroX][charLab.heroY] = true;
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY + 2] = 4;
			charLab.attempts--;
			setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
			cout << "\033[0m";
			cout << " ";
			charLab.heroY += 2;
			charLab.last_click_button = 3;
			isClick = true;
		}
	}
	// Нажатие на "D".
	else if ((GetAsyncKeyState(0x44) & 0x8000) &&
		(GetAsyncKeyState(0x51) & 0x8000) &&
		charLab.busyCoordLabyrint[charLab.heroX + 2][charLab.heroY] == 1) {
		if (!was_passed_button()) {
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY] = 1;
			charLab.explored_way[charLab.heroX][charLab.heroY] = true;
			charLab.busyCoordLabyrint[charLab.heroX + 2][charLab.heroY] = 4;
			charLab.attempts--;
			setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
			cout << "\033[0m";
			cout << " ";
			charLab.heroX += 2;
			charLab.last_click_button = 4;
			isClick = true;
		}
	}
	// Нажатие на "A".
	else if ((GetAsyncKeyState(0x41) & 0x8000) &&
		(GetAsyncKeyState(0x51) & 0x8000) &&
		charLab.busyCoordLabyrint[charLab.heroX - 2][charLab.heroY] == 1) {
		if (!was_passed_button()) {
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY] = 1;
			charLab.explored_way[charLab.heroX][charLab.heroY] = true;
			charLab.busyCoordLabyrint[charLab.heroX - 2][charLab.heroY] = 4;
			charLab.attempts--;
			setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
			cout << "\033[0m";
			cout << " ";
			charLab.heroX -= 2;
			charLab.last_click_button = 2;
			isClick = true;
		}
	}
	// Если персонаж переместился.
	if (isClick) {
		charLab.count_teleport--;
		fileEnd();
		// Перекрашиваем новую ячейку позиции персонажа.
		cout << "\033[43m";
		setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
		cout << " ";
		cout << "\033[0m";

		// Обновляем количество попыток.
		setCursorPosition(9, charLab.labyrinthHeight);
		cout << "                              ";
		setCursorPosition(9, charLab.labyrinthHeight);
		cout << "" << charLab.attempts << " попыток";

		// Обновляем количество телепортаций.
		setCursorPosition(9, charLab.labyrinthHeight + 1);
		cout << "                              ";
		setCursorPosition(9, charLab.labyrinthHeight + 1);
		cout << "" << charLab.count_teleport << " телепортаций";

	}
}