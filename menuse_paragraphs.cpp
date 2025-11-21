#include "main_menu.h"



void printCenter(const string TEXT, bool isPrintTitle) {
	if (isPrintTitle) {
		cout << string(getConsoleHeight() / 2 - 6, '\n');
	}
	cout << string(65, ' ') << TEXT;
}

int getConsoleHeight() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}
	return -1;
}

short clickButton() {
	short whatButtonWasClicked = 0;
	while (true) {
		if (GetAsyncKeyState('1') & 0x8000) {
			whatButtonWasClicked = 1;
			break;
		}
		if (GetAsyncKeyState('2') & 0x8000) {
			whatButtonWasClicked = 2;
			break;
		}
		if (GetAsyncKeyState('3') & 0x8000) {
			whatButtonWasClicked = 3;
			break;
		}
		if (GetAsyncKeyState('4') & 0x8000) {
			whatButtonWasClicked = 4;
			break;
		}
		if (GetAsyncKeyState('5') & 0x8000) {
			whatButtonWasClicked = 5;
			break;
		}
	}
	if (!was_passed_button()) {
		return whatButtonWasClicked;
	}
}

void startGame() {
	installAttempts();
	system("cls");
	Room room;
	Labirinth lab;
	Hero person;
	lab.generation_labyrint();
	lab.print_labyrint();

	// Выход в главное меню.
	while (true) {
		if (GetAsyncKeyState('1') & 0x8000) {
			if (!was_passed_button()) {
				system("cls");
				break;
			}
		}
		person.hero_handler();

	}
	mainMenu();
}

void loadGame() {
	system("cls");
	cout << R"(Функция на данный момент не доступна.
Для выхода в главное меню нажмите 2)";
	while (true) {
		// Выход в главное меню.
		if (GetAsyncKeyState('2') & 0x8000) {
			if (!was_passed_button()) {
				system("cls");
				break;
			}
		}
	}
	mainMenu();
}

void drawSettings(bool isLeft) {
	system("cls");

	printCenter("Настройки", true);
	cout << endl;
	printCenter("");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (isLeft) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "\b\b- ";
	}
	else {
		cout << "\b\b- ";
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << "Размер лабиринта - ";
	cout << charLab.labyrinthWidth << "x" << charLab.labyrinthHeight;

	if (isLeft) {
		cout << " +";
	}
	else {
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << " +";
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << endl;
	printCenter("Сложность: ");
	cout << charLab.complexity;
}

void settings() {

	bool isLeft = false;

	drawSettings(isLeft);
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			if (!was_passed_button()) {
				system("cls");
				break;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			isLeft = false;
			system("cls");
			drawSettings(isLeft);
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			isLeft = true;
			system("cls");
			drawSettings(isLeft);
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (isLeft && charLab.labyrinthWidth != 39) {
				charLab.labyrinthWidth -= 20;
				charLab.labyrinthHeight -= 10;
				charLab.complexity = charLab.labyrinthWidth == 39 ? "Легко" :
					charLab.labyrinthWidth == 59 ? "Средне" :
					charLab.labyrinthWidth == 79 ? "Сложно" :
					"Невозможно";
			}
			else if (!isLeft && charLab.labyrinthWidth < 99) {
				charLab.labyrinthWidth += 20;
				charLab.labyrinthHeight += 10;
				charLab.complexity = charLab.labyrinthWidth == 39 ? "Легко" :
					charLab.labyrinthWidth == 59 ? "Средне" :
					charLab.labyrinthWidth == 79 ? "Сложно" :
					"Невозможно";
			}
			fileEnd();
			system("cls");
			drawSettings(isLeft);
		}
		Sleep(100);
	}
	mainMenu();
}

void aboutProgramm()
{
	system("cls");
	cout << R"(Версия программы: 3.0.
Выполнил: Никита Довгун
Для выхода в главное меню нажмите 4)";
	while (true) {
		if (GetAsyncKeyState('4') & 0x8000) {
			if (!was_passed_button()) {
				system("cls");
				break;
			}
		}
	}
	mainMenu();
}

void fileStart() {
	const string PATH = "settings.json";
	fstream file(PATH, ios::in);
	if (!file.is_open()) {
		file.open(PATH, ios::out);
		if (!file.is_open()) {
			cout << "Ошибка при запуске приложения! Повторите попытку.";
			exit(0);
		}
		json data;
		data["labyrinthWidth"] = 39;
		data["labyrinthHeight"] = 19;
		data["complexity"] = "Легко";

		file << data.dump(4);
		file.close();
	}
	else {
		json data;
		file >> data;
		file.close();
		charLab.labyrinthHeight = data["labyrinthHeight"];
		charLab.labyrinthWidth = data["labyrinthWidth"];
		charLab.complexity = data["complexity"];
	}
}

void fileEnd() {
	const string PATH = "settings.json";
	json data;

	data["labyrinthWidth"] = charLab.labyrinthWidth;
	data["labyrinthHeight"] = charLab.labyrinthHeight;
	data["complexity"] = charLab.complexity;

	fstream file(PATH);
	if (!file.is_open()) {
		cout << "Ошибка сохранения";
		exit(0);
	}

	file << data.dump(4);
	file.close();

}

short was_passed_button() {
	bool button = false;
	while (true) {
		// Проверка на нажатие "Enter".
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "Escape".
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "1".
		else if (GetAsyncKeyState('1') & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "2".
		else if (GetAsyncKeyState('2') & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "3".
		else if (GetAsyncKeyState('3') & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "4".
		else if (GetAsyncKeyState('4') & 0x8000) {
			button = true;
		}
		// Проверка на нажатие "5".
		else if (GetAsyncKeyState('5') & 0x8000) {
			button = true;
		}
		else if (button) {
			button = false;
			return 0;
		}
	}
	return 1;
}

void installAttempts() {
	charLab.attempts = (charLab.labyrinthWidth * charLab.labyrinthHeight) / 2;
}