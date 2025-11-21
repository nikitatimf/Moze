#include <iostream>
#include <string>

#include "main_menu.h"
using namespace std;

int main() {
	fileStart();

	cout << "Для начала игры нажмите кнопку F11";
	while (true) {
		if (GetAsyncKeyState(VK_F11) & 0x8000) {
			system("cls");
			break;
		}
	}

	mainMenu();
	return 0;
}





