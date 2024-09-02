#include "../../include/observadores/ObservadorFase.h"
#include "../../include/gerenciadores/Gerenciador_Eventos.h"

namespace Observadores
{
    ObservadorFase::ObservadorFase(Estados::Fases::Fase* pF):
    Observador(Gerenciadores::Gerenciador_Eventos::getInstancia()),
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

        }
    }

    void ObservadorFase::teclaSolta(const sf::Keyboard::Key tecla)
    {
    }
}