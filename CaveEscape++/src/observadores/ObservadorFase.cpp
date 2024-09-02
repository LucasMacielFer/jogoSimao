#include "../../include/observadores/ObservadorFase.h"
#include "../../include/gerenciadores/GerenciadorEventos.h"

namespace Observadores
{
    ObservadorFase::ObservadorFase(Estados::Fases::Fase* pF):
    Observador(Gerenciadores::GerenciadorEventos::getInstancia()),
    pFase(pF)
    {
    }

    ObservadorFase::~ObservadorFase()
    {
    }

    void ObservadorFase::teclaPressionada(const sf::Keyboard::Key tecla)
    {
        if(tecladoEspecial[tecla] == "Escape")
        {
            pFase->pausar();
        }
    }

    void ObservadorFase::teclaSolta(const sf::Keyboard::Key tecla)
    {
    }
}