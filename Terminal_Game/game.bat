@echo off
pushd "%~dp0"
g++ -std=c++23 -Iinclude main.cpp src/Global.cpp src/Currency.cpp src/Item.cpp src/Building.cpp src/Town.cpp src/Character.cpp src/Menu.cpp -o game
game.exe
