#include "Vizor.h"

void Vizor::vizibility() {
	// Показываем ячейку сверху.
	if (charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY - 1] == 1) {
		setCursorPosition(charLab.heroX - 1, charLab.heroY - 2);
		cout << " ";
	}
	// Показываем ячейку справа.
	if (charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY] == 1) {
		setCursorPosition(charLab.heroX, charLab.heroY - 1); //
		cout << " ";
	}
	// Показываем ячейку снизу.
	if (charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY + 1] == 1) {
		setCursorPosition(charLab.heroX - 1, charLab.heroY); //
		cout << " ";
	}
	// Показываем ячейку слева.
	if (charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY] == 1) {
		setCursorPosition(charLab.heroX - 2, charLab.heroY - 1);
		cout << " ";
	}

	// Показываем ячейку верхнего-правого угла.
	if (charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY - 1] == 1) {
		setCursorPosition(charLab.heroX, charLab.heroY - 2);
		cout << " ";
	}
	// Показываем ячейку нижнего-правого угла.
	if (charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY + 1] == 1) {
		setCursorPosition(charLab.heroX, charLab.heroY);
		cout << " ";
	}
	// Показываем ячейку нижнего-левого угола.
	if (charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY + 1] == 1) {
		setCursorPosition(charLab.heroX - 2, charLab.heroY);
		cout << " ";
	}
	// Показываем ячейку верхнего-левого угла.
	if (charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY - 1] == 1) {
		setCursorPosition(charLab.heroX - 2, charLab.heroY - 2);
		cout << " ";
	}

	// Скрываем ячейки, к которым игрок не имеет доступа (он переместился).
	switch (charLab.last_click_button) {
	// w.
	case 1:
		cout << "\033[47m";
		// Скрываем ячейку нижнего-левого угла.
		if (!charLab.explored_way[charLab.heroX - 1][charLab.heroY + 2] && 
			 charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY + 2] != 3) {
			setCursorPosition(charLab.heroX - 2, charLab.heroY + 1);
			cout << " ";
		}
		// Скрываем ячейку снизу.
		if (!charLab.explored_way[charLab.heroX][charLab.heroY + 2] &&
			 charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY + 2] != 3) {
			setCursorPosition(charLab.heroX - 1, charLab.heroY + 1);
			cout << " ";
		}
		// Скрываем ячейку нижнего-правого угла.
		if (!charLab.explored_way[charLab.heroX + 1][charLab.heroY + 2] &&
			 charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY + 2] != 3) {
			setCursorPosition(charLab.heroX, charLab.heroY + 1);
			cout << " ";
		}
		cout << "\033[40m";
		break;
	// a.
	case 2:
		cout << "\033[47m";
		// Скрываем ячейку верхнего-левого угла.
		if (!charLab.explored_way[charLab.heroX + 2][charLab.heroY - 1] &&
			charLab.busyCoordLabyrint[charLab.heroX + 2][charLab.heroY - 1] != 3) {
			setCursorPosition(charLab.heroX + 1, charLab.heroY - 2);
			cout << " ";
		}
		// Скрываем ячейку слева.
		if (!charLab.explored_way[charLab.heroX + 2][charLab.heroY] &&
			charLab.busyCoordLabyrint[charLab.heroX + 2][charLab.heroY] != 3) {
			setCursorPosition(charLab.heroX + 1, charLab.heroY - 1);
			cout << " ";
		}
		// Скрываем ячейку нижнего-левого угла.
		if (!charLab.explored_way[charLab.heroX + 2][charLab.heroY + 1] &&
			charLab.busyCoordLabyrint[charLab.heroX + 2][charLab.heroY + 1] != 3) {
			setCursorPosition(charLab.heroX + 1, charLab.heroY);
			cout << " ";
		}
		cout << "\033[40m";
		break;
	// s.
	case 3:
		cout << "\033[47m";
		// Скрываем ячейку верхнего-левого угла.
		if (!charLab.explored_way[charLab.heroX - 1][charLab.heroY - 2] &&
			charLab.busyCoordLabyrint[charLab.heroX - 1][charLab.heroY - 2] != 3) {
			setCursorPosition(charLab.heroX - 2, charLab.heroY - 3);
			cout << " ";
		}
		// Скрываем ячейку сверху.
		if (!charLab.explored_way[charLab.heroX][charLab.heroY - 2] &&
			charLab.busyCoordLabyrint[charLab.heroX][charLab.heroY - 2] != 3) {
			setCursorPosition(charLab.heroX - 1, charLab.heroY - 3);
			cout << " ";
		}
		// Скрываем ячейку верхнего-правого угла.
		if (!charLab.explored_way[charLab.heroX + 1][charLab.heroY - 2] &&
			charLab.busyCoordLabyrint[charLab.heroX + 1][charLab.heroY - 2] != 3) {
			setCursorPosition(charLab.heroX, charLab.heroY - 3);
			cout << " ";
		}
		cout << "\033[40m";
		break;
	// d.
	case 4:
		cout << "\033[47m";
		// Скрываем ячейку верхнего-левого угла.
		if (!charLab.explored_way[charLab.heroX - 2][charLab.heroY - 1] &&
			charLab.busyCoordLabyrint[charLab.heroX - 2][charLab.heroY - 1] != 3) {
			setCursorPosition(charLab.heroX - 3, charLab.heroY - 2);
			cout << " ";
		}
		// Скрываем ячейку слева.
		if (!charLab.explored_way[charLab.heroX - 2][charLab.heroY] &&
			charLab.busyCoordLabyrint[charLab.heroX - 2][charLab.heroY] != 3) {
			setCursorPosition(charLab.heroX - 3, charLab.heroY - 1);
			cout << " ";
		}
		// Скрываем ячейку нижнего-левого угла.
		if (!charLab.explored_way[charLab.heroX - 2][charLab.heroY + 1] &&
			charLab.busyCoordLabyrint[charLab.heroX - 2][charLab.heroY + 1] != 3) {
			setCursorPosition(charLab.heroX - 3, charLab.heroY);
			cout << " ";
		}
		cout << "\033[40m";
		break;
	}
}