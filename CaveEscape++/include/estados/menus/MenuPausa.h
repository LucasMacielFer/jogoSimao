#pragma once
#include "Menu.h"
#include "../fases/Fase.h"
#include <string>

namespace Estados
{
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
                void selecionar();
                void criarBotoes();
        };
    }
}