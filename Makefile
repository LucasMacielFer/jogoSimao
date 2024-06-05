all:
	g++ -c src/main.cpp src/game.cpp src/game-parts/level.cpp src/elements/entities/entity.cpp src/elements/entities/player.cpp
	g++ main.o game.o level.o entity.o player.o -o jogo -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm main.o sfml-app