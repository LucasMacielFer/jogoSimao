FILES = main game level entity player
CPP = $(wildcard src/*.cpp) $(wildcard src/game-parts/*.cpp) $(wildcard src/elements/entities/*.cpp) $(wildcard src/elements/scenario/*.cpp)
ODIR = bin
OBJ = $(patsubst src/elements/entities/%.cpp,$(ODIR)/%.o, $(wildcard src/elements/entities/*.cpp))
OBJ += $(patsubst src/elements/scenario/%.cpp,$(ODIR)/%.o, $(wildcard src/elements/scenario/*.cpp))
OBJ += $(patsubst src/game-parts/%.cpp,$(ODIR)/%.o, $(wildcard src/game-parts/*.cpp))
OBJ += $(patsubst src/%.cpp,$(ODIR)/%.o, $(wildcard src/*.cpp))


$(ODIR)/%.o:: src/elements/entities/%.cpp
	g++ -Iinclude -g -fsanitize=address -c -o $@ $<

$(ODIR)/%.o:: src/elements/scenario/%.cpp
	g++ -Iinclude -g -fsanitize=address -c -o $@ $<

$(ODIR)/%.o:: src/game-parts/%.cpp
	g++ -Iinclude -g -fsanitize=address -c -o $@ $<

$(ODIR)/%.o:: src/%.cpp
	g++ -Iinclude -g -fsanitize=address -c -o $@ $<

all: $(OBJ)
	g++ -Iinclude -g -fsanitize=address $(OBJ) -o jogo -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm bin/*.o jogo