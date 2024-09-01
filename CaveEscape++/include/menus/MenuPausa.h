#pragma once
#include "Menu.h"
#include "../estados/fases/Fase.h"
#include <string>

namespace Menus
{
    class MenuPausa : public Menu
    {
        private:
            Estados::Fases::Fase* faseApontada;
            bool saida;

        public:

            MenuPausa(Estados::Fases::Fase* pFase = NULL);
            ~MenuPausa();

            void setFase(Estados::Fases::Fase* faseEscolhida);
            Estados::Fases::Fase* getFase();
            void criarBotoes();
            void executar();

    };

}