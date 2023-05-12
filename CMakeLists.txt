cmake_minimum_required(VERSION 3.24)
project(Proyecto2Pacman)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto2Pacman main.cpp Sources/ApplicationManager.cpp Headers/ApplicationManager.h Sources/WindowStateStack.cpp DataStructures/WindowStateStack.h Sources/WindowState.cpp Headers/WindowState.h Sources/MainWindow.cpp Headers/MainWindow.h Sources/SfmlButton.cpp Sources/GameWindow.cpp Headers/GameWindow.h Sources/Cell.cpp Headers/Cell.h Sources/LevelData.cpp Headers/LevelData.h Sources/Enemy.cpp Headers/Enemy.h Sources/Enemy.cpp Sources/PathFinding.cpp Headers/PathFinding.h Sources/IntegerLinkedList.cpp DataStructures/IntegerLinkedList.h)

target_link_libraries(Proyecto2Pacman sfml-graphics sfml-window sfml-system)