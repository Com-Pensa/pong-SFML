#! bin/bash

g++ -c src/main.cpp src/Game.cpp
g++ main.o Game.o -o pong-SFML -lsfml-graphics -lsfml-window -lsfml-system
./pong-SFML
