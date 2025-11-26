#include "Hero.h"

bool Hero::hero_handler() {
	// Если закончились попытки.
	if (!charLab.attempts) {
		lose_function();
	}

	bool isClick = false;
	// Нажатие на "W".
	// Если была нажата клавиша, и ячека, в которую игрок собирается переместится - проход.
	if ((GetAsyncKeyState(0x57) & 0x8000) && charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY - 1] == 1) {
		if (!was_passed_button()) {
			// Изменяем индекс ячейки текущей позиции персонажа на 1.
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY] = 1;
			// Именяем состояние ячейки тукущей позиции игрока на исслодованно.
			charLab.explored_way[charLab.heroX][charLab.heroY] = true;
			// Изменяем индекс ячейки в которую перемещается персонаж на 4.
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY - 1] = 4;
			charLab.attempts--;
			// Перекрашиваем ячейку прошлой позиции персонажа в цвет прохода.
			setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
			cout << "\033[0m";
			cout << " ";
			charLab.heroY--;
			isClick = true;
		}
	}
	// Нажатие на "S".
	else if ((GetAsyncKeyState(0x53) & 0x8000) && charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY + 1] == 1) {
		if (!was_passed_button()) {
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY] = 1;
			charLab.explored_way[charLab.heroX][charLab.heroY] = true;
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY + 1] = 4;
			charLab.attempts--;
			setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
			cout << "\033[0m";
			cout << " ";
			charLab.heroY++;
			isClick = true;
		}
	}
	// Нажатие на "D".
	else if ((GetAsyncKeyState(0x44) & 0x8000) && charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY] == 1) {
		if (!was_passed_button()) {
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY] = 1;
			charLab.explored_way[charLab.heroX][charLab.heroY] = true;
			charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY] = 4;
			charLab.attempts--;
			setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
			cout << "\033[0m";
			cout << " ";
			charLab.heroX++;
			isClick = true;
		}
	}
	// Нажатие на "A".
	else if ((GetAsyncKeyState(0x41) & 0x8000) && charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY] == 1) {
		if (!was_passed_button()) {
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY] = 1;
			charLab.explored_way[charLab.heroX][charLab.heroY] = true;
			charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY] = 4;
			charLab.attempts--;
			setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
			cout << "\033[0m";
			cout << " ";
			charLab.heroX--;
			isClick = true;
		}
	}
	// Если персонаж переместился.
	if (isClick) {
		fileEnd();
		// Перекрашиваем новую ячейку позиции персонажа.
		cout << "\033[43m"; 
		setCursorPosition(charLab.heroX - 1, charLab.heroY - 1);
		cout << " ";
		cout << "\033[0m";

		// Обновляем количество попыток.
		cout << "\033[0m";
		setCursorPosition(9, charLab.labyrinthHeight);
		cout << "                              ";
		setCursorPosition(9, charLab.labyrinthHeight);
		cout << "" << charLab.attempts << " попыток";

		// Если игрок добрался до выхода.
		if (charLab.heroX == charLab.labyrinthWidth - 1 && charLab.heroY == charLab.labyrinthHeight - 1) {
			win_function();
		}
	}
	return isClick ? true : false;
}

short Hero::was_passed_button() {
	bool button = false;
	while (true) {
		// Проверка на нажатие "W".
		if (GetAsyncKeyState(0x57) & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "S".
		else if (GetAsyncKeyState(0x53) & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "D".
		else if (GetAsyncKeyState(0x44) & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "A".
		else if (GetAsyncKeyState(0x41) & 0x8000) {
			button = true;
		}
		else if (button) {
			button = false;
			return 0;
		}
	}
	return 1;
}

void Hero::lose_function() {
	charLab.heroX = 2;
	charLab.heroY = 2;
	system("cls");
	cout << "You lose\nPress any Enter to come to main menu";
	while (true) {
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			system("cls");
			mainMenu();
		}
	}
}

void Hero::win_function() {
	charLab.heroX = 2;
	charLab.heroY = 2;
	system("cls");
	cout << "You win\nPress any Enter to come to main menu";
	while (true) {
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			system("cls");
			mainMenu();
		}
	}
}