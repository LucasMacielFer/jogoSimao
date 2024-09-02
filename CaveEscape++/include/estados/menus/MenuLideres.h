#pragma once

#include "Menu.h"
#include <string>
#include <map>
#include <fstream>

#define CAMINHO_TABELA "assets/salvamento/lideres.txt"

namespace Estados
{
    namespace Menus
    {
        class MenuLideres : public Menu
        {
            private:
                std::multimap<int, Texto::ElementoTexto*> mapaLideres;

            public:
                MenuLideres();
                ~MenuLideres();
                void selecionar();
                void criarBotoes();
                void criarTabela(const char* caminhoSalvamento);
                void desenhar(sf::RenderWindow& janela);
        };
    }
}