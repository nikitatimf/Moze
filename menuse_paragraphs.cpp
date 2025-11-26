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
	charLab.heroX = 2;
	charLab.heroY = 2;
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
	fileEnd();
	system("pause");
	mainMenu();
}

void loadGame() {
	system("cls");
	// Выгузка данных из файла.
	const string PATH = "setting.json";
	ifstream file(PATH);
	json data;
	file >> data;
	file.close();
	charLab.labyrinthHeight = data["labyrinthHeight"];
	charLab.labyrinthWidth = data["labyrinthWidth"];
	charLab.complexity = data["complexity"];
	
	charLab.heroX = data["heroX"];
	charLab.heroY = data["heroY"];
	charLab.attempts = data["attempts"];

	Room room;
	Labirinth lab;
	Hero person;

	for (short i = 0; i < charLab.labyrinthWidth + 2; i++) {
		for (short j = 0; j < charLab.labyrinthHeight + 2; j++) {
			charLab.busyCoordLabyrint[i][j] = data["busyCoordLabyrint"][i][j].get<short>();
		}
	}
	for (short i = 0; i < charLab.labyrinthWidth + 2; i++) {
		for (short j = 0; j < charLab.labyrinthHeight + 2; j++) {
			charLab.explored_way[i][j] = data["explore_way"][i][j];
		}
	}
	
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
	cout << R"(Версия программы: 4.0.
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
	const string PATH = "setting.json";
	ifstream file(PATH);
	if (!file.is_open()) {
		ofstream file(PATH);
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
	const string PATH = "setting.json";

	ofstream file(PATH); 
	if (!file.is_open()) {
		cout << "Ошибка сохранения";
		exit(0);
	}

	json data;

	data["labyrinthWidth"] = charLab.labyrinthWidth;
	data["labyrinthHeight"] = charLab.labyrinthHeight;
	data["complexity"] = charLab.complexity;
	json busy_arr = json::array();
	if (charLab.busyCoordLabyrint) {
		for (short i = 0; i < charLab.labyrinthWidth + 2; i++) {
			json row = json::array();
			for (short j = 0; j < charLab.labyrinthHeight + 2; j++) {
				row.push_back(charLab.busyCoordLabyrint[i][j]);
			}
			busy_arr.push_back(row);
		}
	}
	data["busyCoordLabyrint"] = busy_arr;
	data["heroX"] = charLab.heroX;
	data["heroY"] = charLab.heroY;
	data["attempts"] = charLab.attempts;
	json explore_arr = json::array();
	if (charLab.explored_way) {
		for (short i = 0; i < charLab.labyrinthWidth + 2; i++) {
			json row = json::array();
			for (short j = 0; j < charLab.labyrinthHeight + 2; j++) {
				row.push_back(charLab.explored_way[i][j]);
			}
			explore_arr.push_back(row);
		}
	}
	data["explore_way"] = explore_arr;

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