#include "main_menu.h"

void mainMenu() {
	printCenter("Побег из лабиринта", true);
	cout << endl;
	printCenter("1. Начать игру");
	cout << endl;
	printCenter("2. Загрузить игру");
	cout << endl;
	printCenter("3. Рейтинговая таблица");
	cout << endl;
	printCenter("4. Настройки");
	cout << endl;
	printCenter("5. О программе");
	cout << endl;
	printCenter("6. Выход");

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
		rating();
		break;
	}
	case 4: {
		settings();
		break;
	}
	case 5: {
		aboutProgramm();
		break;
	}
	case 6: {
		fileEnd();
		exit(0);
	}
	}
}