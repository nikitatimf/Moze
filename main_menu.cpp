#include "main_menu.h"

void mainMenu() {
	printCenter("Побег из лабиринта", true);
	cout << endl;
	printCenter("1. Начать игру");
	cout << endl;
	printCenter("2. Загрузить игру");
	cout << endl;
	printCenter("3. Настройки");
	cout << endl;
	printCenter("4. О программе");
	cout << endl;
	printCenter("5. Выход");

	short whatButtonWasClicked = clickButton();
	switch (whatButtonWasClicked) {
	case 1: {
		startGame();
		break;
	}
	case 2: {
		loadGame();
		break;
	}
	case 3: {
		settings();
		break;
	}
	case 4: {
		aboutProgramm();
		break;
	}
	case 5: {
		fileEnd();
		exit(0);
	}
	}
}