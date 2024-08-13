FILES = main Ente Gerenciador_Grafico Gerenciador_Eventos Entidade Personagem
CPP = $(wildcard src/*.cpp) $(wildcard src/gerenciadores/*.cpp) $(wildcard src/entidades/*.cpp) $(wildcard src/entidades/personagens/*.cpp)
ODIR = bin
OBJ = $(patsubst src/gerenciadores/%.cpp,$(ODIR)/%.o, $(wildcard src/gerenciadores/*.cpp))
OBJ += $(patsubst src/entidades/%.cpp,$(ODIR)/%.o, $(wildcard src/entidades/*.cpp))
OBJ += $(patsubst src/entidades/personagens/%.cpp,$(ODIR)/%.o, $(wildcard src/entidades/personagens/*.cpp))
OBJ += $(patsubst src/%.cpp,$(ODIR)/%.o, $(wildcard src/*.cpp))


$(ODIR)/%.o:: src/gerenciadores/%.cpp
	g++ -Iinclude -g -fsanitize=address -c -o $@ $<

$(ODIR)/%.o:: src/entidades/%.cpp
	g++ -Iinclude -g -fsanitize=address -c -o $@ $<

$(ODIR)/%.o:: src/entidades/personagens/%.cpp
	g++ -Iinclude -g -fsanitize=address -c -o $@ $<

$(ODIR)/%.o:: src/%.cpp
	g++ -Iinclude -g -fsanitize=address -c -o $@ $<

all: $(OBJ)
	g++ -Iinclude -g -fsanitize=address $(OBJ) -o jogo -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm bin/*.o jogo