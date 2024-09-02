#pragma once

#include "Observador.h"
#include "../estados/fases/Fase.h"

namespace Observadores
{
    // Classe baseada no código do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
    class ObservadorFase : public Observador
    {   
        private:
            Estados::Fases::Fase* pFase;

        public:
            ObservadorFase(Estados::Fases::Fase* pF);
            ~ObservadorFase();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
    };
}