default:
	g++ src/main.cpp src/Game.cpp src/Entity.cpp src/Components.cpp -std=c++17 -lsfml-window -lsfml-graphics -lsfml-system -o bin/chess