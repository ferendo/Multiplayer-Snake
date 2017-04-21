//
// Created by dylan on 14/04/2017.
//

#ifndef SNAKES_CLIENTLAYOUT_H
#define SNAKES_CLIENTLAYOUT_H

#include <ncurses.h>
#include "../../utility/Vector.h"
#include "../../server/Food.h"

// Put 0 for clean border
#define MAIN_MENU_BORDER_CHARACTER '+'
#define MAIN_MENU_DIVIDER '-'
#define MAIN_MENU_ITEMS 3
#define PLAY_GAME_MENU_REQUIRED 2
#define PLAY_GAME_MENU_LENGTH 13

#define ERROR_NO_HOST "Error, no such host!"
#define ERROR_CONNECTION_FAILED "Error, connection failed!"

#define SNAKE_CHARACTER "#"

const char * const MENU_ITEMS[MAIN_MENU_ITEMS];

const char * const CREDITS;

const char * const SERVER_REQUIRED[PLAY_GAME_MENU_REQUIRED];

void createOutsideBorder();

WINDOW * createMainMenuWindow();

void aboutMenu();

void getInput(char * serverName, char * port);

bool printErrorAndOfferRetry(char *errorMessage);

WINDOW * generatePlayingWindow();

void deleteWindow(WINDOW *window);

WINDOW * createWindowAtTheCenterOfTheScreen(int height);

void showWinnerScreen();

void showDeadScreen();

void serverErrorScreen();

const chtype foodType(Food * type);

WINDOW * displayNewData(Vector * foods, Vector * connections);

#endif //SNAKES_CLIENTLAYOUT_H