#pragma once

#include "Menu.h"
#include <string>
#include <fstream>

namespace Estados
{
    namespace Menus
    {
        class MenuSalvar : public Menu
        {
            private:
                Texto::ElementoTexto* nomeJogador;

            public:
                MenuSalvar();
                ~MenuSalvar();
                void selecionar();
                void criarBotoes();
                void digitar(char c);
                void deletar();
                void desenhar(sf::RenderWindow& janela);
                void salvar(const char* caminhoSalvamento);
        };
    }
}