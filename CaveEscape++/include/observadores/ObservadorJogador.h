#pragma once

#include "Observador.h"
#include "../entidades/personagens/Jogador.h"

namespace Observadores
{
    // Classe baseada no código do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
    class ObservadorJogador : public Observador
    {
        private:
            Entidades::Personagens::Jogador* pJogador;
            int numeroJogador;

        public:
            ObservadorJogador(const int numJog, Entidades::Personagens::Jogador* pJ);
            ~ObservadorJogador();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
    };
}