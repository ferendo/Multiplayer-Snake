cmake_minimum_required(VERSION 3.5.1)
project(Snakes)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pthread")

set(CLIENT_FILES
        src/utility/Vector.c
        src/utility/General.c
        src/utility/Serialize.c
        src/client/template/ClientLayout.c
        src/client/Client.c
        src/client/ConnectMenu.c
        src/utility/Vector.h
        src/utility/General.h
        src/utility/Serialize.h
        src/client/template/ClientLayout.h
        src/client/ConnectMenu.h
        src/client/SnakesGame.h
        src/client/SnakesGame.c
        src/settings/GameSettings.h
        src/utility/LinkedList.c
        src/utility/LinkedList.h
        src/client/API/ClientAPI.h
        src/client/API/ClientAPI.c)

set(SERVER_FILES
        src/utility/Vector.c
        src/utility/Serialize.c
        src/server/Server.c
        src/utility/Vector.h
        src/utility/Serialize.h
        src/server/Server.h
        src/server/Snake.h
        src/server/Snake.c
        src/settings/GameSettings.h
        src/utility/RandomUtility.c
        src/utility/RandomUtility.h
        src/utility/LinkedList.c
        src/utility/LinkedList.h
        src/utility/General.c
        src/utility/General.h
        src/server/Game.h
        src/server/Game.c
        src/server/Food.h
        src/server/Food.c
        src/server/SnakeMove.h
        src/server/SnakeMove.c
        src/server/ServerHandle.c
        src/server/ServerHandle.h
        src/server/API/SnakesAPI.h
        src/server/API/SnakesAPI.c)

add_executable(Client ${CLIENT_FILES})
add_executable(Server ${SERVER_FILES})

# Add ncurses library
find_package(Curses  REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})
target_link_libraries( Client ${CURSES_LIBRARIES})