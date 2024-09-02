#pragma once
#include "../../Ente.h"
#include "Menu.h"
#include <string>

namespace Estados
{
    namespace Menus
    {
        class MenuPrincipal : public Menu
        {
            private:
                bool saida;

            public:
                MenuPrincipal();
                ~MenuPrincipal();
                void selecionar();
                void criarBotoes();
        };
    }
}