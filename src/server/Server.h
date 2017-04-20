//
// Created by dylan on 14/04/2017.
//

#ifndef SNAKES_SERVERLAUNCHER_H
#define SNAKES_SERVERLAUNCHER_H

#include "../utility/Vector.h"
#include "Snake.h"
#include "../template/GameSettings.h"
#include <stdbool.h>
#include <netinet/in.h>

typedef struct ClientInfo {
    char name[MAXIMUM_INPUT_STRING];
    short isHost;
    Snake * snake;
} ClientInfo;

typedef struct Connection {
    int sockFd;
    ClientInfo * clientInfo;
} Connection;

typedef struct CreateConnectThreadArguments {
    short isHost;
    int sockFd;
} CreateConnectThreadArguments;

// Vector containing Connections Type
extern Vector * connections;
// Contains the food.
extern Vector * foods;
// Lock
extern pthread_mutex_t lock;
// Contains the initial positions of all snakes.
extern Vector * initialPositions;

int main(int argc, char *argv[]);

void serverInit(uint16_t portNumber);

void acceptClients(int sockFd, struct sockaddr * clientAddress, socklen_t * clientSize);

#endif //SNAKES_SERVERLAUNCHER_H