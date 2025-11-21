#pragma once
// Подфункции главного меню. 

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

#include "Hero.h"
#include "Room.h"
#include "Labirinth.h"
#include "charlab.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

// Функция для перемещения главного меню по центру по горизонтали.
void printCenter(const string TEXT, bool isPrintTitle = false);

// Функция для перемещения главного меню по центру по вертикали
int getConsoleHeight();

// Функция для отслеживания нажатий кнопок в главном меню.
short clickButton();

// Функция окна, появляющегося после выбора "Начать игру".
void startGame();

// Функция окна "Загрузить игру".
void loadGame();

// Функция, рисующая окно "Настройки".
void drawSettings(bool isLeft);

// Функция окна "Настройки".
void settings();

// Функция окна "О программе".
void aboutProgramm();

// Функция для начала работы с файлом.
void fileStart();

// Функция для конца работы с файлом.
void fileEnd();

// Функция, проверяющая, была ли отпущена клавиша Enter, S, W.
// Если была отпущена - возвращается 0, иначе - 1.
short was_passed_button();

// Функция, устанавливающая число попыток.
void installAttempts();

