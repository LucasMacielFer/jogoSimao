#pragma once
#include "Ente.h"
#include "Menu.h"
#include <string>

namespace Menus
{
    class MenuPrincipal : public Menu
    {
        private:
            bool saida;

        public:

            MenuPrincipal();
            ~MenuPrincipal();

            void criarBotoes();
            void executar();

    };

}