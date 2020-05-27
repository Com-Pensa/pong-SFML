#!/bin/bash

# Compiling and linking:
g++ -c src/components/main.cpp src/components/Game.cpp src/components/obj/Player.cpp src/components/obj/Ball.cpp
g++ main.o Game.o Player.o Ball.o -o pong-SFML -lsfml-graphics -lsfml-window -lsfml-system

rm main.o Game.o Player.o Ball.o  # Deleting files that doesnt't necessary anymore

./pong-SFML # Executing...
