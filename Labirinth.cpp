#include "Labirinth.h"

Labirinth::Labirinth() :
	X(charLab.labyrinthWidth), Y(charLab.labyrinthHeight),
	busyX(X + 2), busyY(Y + 2)
{
	// Инициализация матрицы начальными значениями: 0 и 3.
	charLab.busyCoordLabyrint = new short* [busyX];
	for (short x = 0; x < busyX; x++) {
		charLab.busyCoordLabyrint[x] = new short[busyY];
		for (short y = 0; y < busyY; y++) {
			if (x == 1 || x == busyX - 2 || 
				y == 1 || y == busyY - 2) {
				charLab.busyCoordLabyrint[x][y] = 3;
				continue;
			}
			charLab.busyCoordLabyrint[x][y] = 0;
		}
	}


}

void Labirinth::print_labyrint() {
	for (int y = 1; y < busyY - 1; y++) {
		for (int x = 1; x < busyX - 1; x++) {
			// Стандартный цвет для неисследованной области.
			cout << "\033[47;30m";
			// Если граница.
			if (charLab.busyCoordLabyrint[x][y] == 3) {
				cout << "\033[42m";
			}
			setCursorPosition(x - 1, y - 1);
			cout << " ";
		}
	}
	// Окрашивание ячейки начальной позиции персонажа.
	setCursorPosition(1, 1); 
	cout << "\033[43m";
	cout << " ";

	cout << "\033[0m";
	setCursorPosition(X - 2, Y - 2);
	cout << " \n\n";
	cout << "Осталось " << charLab.attempts << " попыток";
}

void Labirinth::addToAvailableCoord(cell p) {
	charLab.busyCoordLabyrint[p.x ][p.y] = 1;

	// Меняем индекс ячейки между новообразовавшейся ячейкой
	// под индексом 1 и ее родителем.
	// Рисует вверх
	if (p.parentY < p.y) {
		charLab.busyCoordLabyrint[p.x][p.y - 1] = 1;
	}
	//Рисует вправо.
	else if (p.parentX > p.x) {
		charLab.busyCoordLabyrint[p.x + 1][p.y] = 1;
	}
	// Рисует вниз.
	else if (p.parentY > p.y) {
		charLab.busyCoordLabyrint[p.x][p.y + 1] = 1;
	}
	// Рисует влево.
	else if (p.parentX < p.x) {
		charLab.busyCoordLabyrint[p.x - 1][p.y] = 1;
	}

	// Формирование дочерних ячеек для новообразовавшейся ячейки
	// под индексом 1.
	// Проверяется предпологаемая дочерняя ячейка на то,
	// чтобы ее индекс был равен 0, и ячейка между новообразовавшейся 
	// и предпологаемой дочерней ячейкой не была границей (под индексом 3).
	// Проверка вверх.
	if (charLab.busyCoordLabyrint[p.x][p.y - 2] == 0 &&
		charLab.busyCoordLabyrint[p.x][p.y - 1] != 3) {
		charLab.busyCoordLabyrint[p.x][p.y - 2] = 2;
		availableCoord.push_back(cell(p.x, p.y - 2, p.x, p.y));
	}
	// Проверка вправо.
	if (charLab.busyCoordLabyrint[p.x + 2][p.y] == 0 &&
		charLab.busyCoordLabyrint[p.x + 1][p.y] != 3) {
		charLab.busyCoordLabyrint[p.x + 2][p.y] = 2;
		availableCoord.push_back(cell(p.x + 2, p.y, p.x, p.y));
	}
	// Проверка вниз.
	if (charLab.busyCoordLabyrint[p.x][p.y + 2] == 0 &&
		charLab.busyCoordLabyrint[p.x][p.y + 1] != 3) {
		charLab.busyCoordLabyrint[p.x][p.y + 2] = 2;
		availableCoord.push_back(cell(p.x, p.y + 2, p.x, p.y));
	}
	// Проверка влево.
	if (charLab.busyCoordLabyrint[p.x - 2][p.y] == 0 &&
		charLab.busyCoordLabyrint[p.x - 1][p.y] != 3) {
		charLab.busyCoordLabyrint[p.x - 2][p.y] = 2;
		availableCoord.push_back(cell(p.x - 2, p.y, p.x, p.y));
	}
		
	// Удаление новообразовавшейся ячейки из вектора.
	auto indxP = find(availableCoord.begin(), availableCoord.end(), p);
	if (indxP != availableCoord.end()) {
		availableCoord.erase(indxP);
	}
}

void Labirinth::generation_labyrint() {
	// Добавление ячейки из которой будет генерироваться лабиринт.
	cell cell2(2, 2, 2, 2);
	availableCoord.push_back(cell2);

	while (!availableCoord.empty()) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(0, availableCoord.size() - 1);

		short randomIndex = dist(gen);
		addToAvailableCoord(availableCoord[randomIndex]);
	}
}

void Labirinth::examples_of_labyrint() {
	while (1) {
		cell cell2(2, 2, 20, 10);
		availableCoord.push_back(cell2);

		while (!availableCoord.empty()) {
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> dist(0, availableCoord.size() - 1);

			short randomIndex = dist(gen);
			addToAvailableCoord(availableCoord[randomIndex]);
		}

		for (int y = 1; y < busyY - 1; y++) {
			for (int x = 1; x < busyX - 1; x++) {
				// Меняем цвета.
				if (charLab.busyCoordLabyrint[x][y] == 0) {
					cout << "\033[47;30m";
				}
				else if (charLab.busyCoordLabyrint[x][y] == 1) {
					cout << "\033[0m";
				}
				else if (charLab.busyCoordLabyrint[x][y] == 2) {
					cout << "\033[41m";
				}
				else if (charLab.busyCoordLabyrint[x][y] == 3) {
					cout << "\033[42m";
				}
				else if (charLab.busyCoordLabyrint[x][y] == 4) {
					cout << "\033[43m";
				}
				setCursorPosition(x - 1, y - 1);
				cout << " ";
			}
		}
		(void)_getch();

		for (short x = 0; x < busyX; x++) {
			charLab.busyCoordLabyrint[x] = new short[busyY];
			for (short y = 0; y < busyY; y++) {
				if (x == 1 || x == busyX - 2 ||
					y == 1 || y == busyY - 2) {
					charLab.busyCoordLabyrint[x][y] = 3;
					continue;
				}
				charLab.busyCoordLabyrint[x][y] = 0;
			}
		}
	}
}

void Labirinth::steps_of_generation_of_labyrint() {
	cell cell2(2, 2, 20, 10);
	availableCoord.push_back(cell2);

	while (!availableCoord.empty()) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(0, availableCoord.size() - 1);

		short randomIndex = dist(gen);
		addToAvailableCoord(availableCoord[randomIndex]);

		(void)_getch();
		for (int y = 1; y < busyY - 1; y++) {
			for (int x = 1; x < busyX - 1; x++) {
				// Меняем цвета.
				if (charLab.busyCoordLabyrint[x][y] == 0) {
					cout << "\033[47;30m";
				}
				else if (charLab.busyCoordLabyrint[x][y] == 1) {
					cout << "\033[0m";
				}
				else if (charLab.busyCoordLabyrint[x][y] == 2) {
					cout << "\033[41m";
				}
				else if (charLab.busyCoordLabyrint[x][y] == 3) {
					cout << "\033[42m";
				}
				else if (charLab.busyCoordLabyrint[x][y] == 4) {
					cout << "\033[43m";
				}
				setCursorPosition(x - 1, y - 1);
				cout << " ";
			}
		}
		
	}
}

















