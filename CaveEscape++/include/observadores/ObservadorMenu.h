#pragma once

#include "Observador.h"
#include "../estados/menus/Menu.h"
#include "../estados/Estado.h"
#include "../estados/menus/MenuSalvar.h"

namespace Observadores
{
    class ObservadorMenu : public Observador
    {
        private:
            Estados::Menus::Menu* pMenu;

        public:
            ObservadorMenu(Estados::Menus::Menu* pM);
            ~ObservadorMenu();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
    };
}