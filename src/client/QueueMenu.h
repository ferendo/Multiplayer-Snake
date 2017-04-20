//
// Created by dylan on 14/04/2017.
//

#ifndef SNAKES_STARTGAME_H
#define SNAKES_STARTGAME_H

#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <ncurses.h>
#include "../server/Server.h"

void serverConnection();

bool connectToServer(int * sockFd, char * playerName);

void writeNameToSocket(int socketFileDescriptor, char * name);

void clearConnectionVector(Vector * oldVector);

Vector * readConnectionsFromSocket(int socketFileDescriptor);

bool printErrorAndOfferRetry(char *errorMessage);

void waitUntilHostStartsGame(int * sockFd, char * playerId);

void writeStartGameToSocket(int * sockFd);

int readDelimiterQueue(int *sockFd);

#endif //SNAKES_STARTGAME_H
