#! bin/bash

g++ -c src/main.cpp src/Game.cpp src/obj/Player.cpp
g++ main.o Game.o Player.o -o pong-SFML -lsfml-graphics -lsfml-window -lsfml-system
./pong-SFML
