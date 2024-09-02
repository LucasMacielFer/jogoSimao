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
                static idEstados fasePausada;
                bool saida;

            public:

                MenuPausa(Estados::Fases::Fase* pFase = NULL);
                ~MenuPausa();

                static void setFase(idEstados faseEscolhida);
                static idEstados getFase();
                void selecionar();
                void criarBotoes();
        };
    }
}