#include "../../include/observadores/ObservadorJogador.h"
#include "../../include/gerenciadores/GerenciadorEventos.h"

namespace Observadores
{
    ObservadorJogador::ObservadorJogador(const int numJog, Entidades::Personagens::Jogador* pJ):
    Observador(Gerenciadores::GerenciadorEventos::getInstancia()),
    numeroJogador(numJog),
    pJogador(pJ)
    {
    }

    ObservadorJogador::~ObservadorJogador()
    {
    }

    void ObservadorJogador::teclaPressionada(const sf::Keyboard::Key tecla)
    {
        if(numeroJogador == 1)
        {
            if(teclado[tecla] == 'a')
            {
                pJogador->movimentaX(-1);
            }
            else if(teclado[tecla] == 'd')
            {
                pJogador->movimentaX(1);
            }
            else if(teclado[tecla] == 'w')
            {
                pJogador->pular();
            }
            else if(teclado[tecla] == 's')
            {
                if(pJogador->ataqueDisponivel())
                    pJogador->atacar();
            }
        }

        else if(numeroJogador == 2)
        {
            if(tecladoEspecial[tecla] == "Left")
            {
                pJogador->movimentaX(-1);
            }
            else if(tecladoEspecial[tecla] == "Right")
            {
                pJogador->movimentaX(1);
            }
            else if(tecladoEspecial[tecla] == "Up")
            {
                pJogador->pular();
            }
            else if(tecladoEspecial[tecla] == "Down")
            {
                if(pJogador->ataqueDisponivel())
                    pJogador->atacar();
            }
        }
    }

    void ObservadorJogador::teclaSolta(const sf::Keyboard::Key tecla)
    {
        if(numeroJogador == 1)
        {
            if(teclado[tecla] == 'a')
            {
                pJogador->movimentaX(0);
            }
            else if(teclado[tecla] == 'd')
            {
                pJogador->movimentaX(0);
            }
        }

        else if(numeroJogador == 2)
        {
            if(tecladoEspecial[tecla] == "Left")
            {
                pJogador->movimentaX(0);
            }
            else if(tecladoEspecial[tecla] == "Right")
            {
                pJogador->movimentaX(0);
            }
        }
    }
}