#pragma once

#include "Observador.h"
#include "../estados/menus/Menu.h"

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