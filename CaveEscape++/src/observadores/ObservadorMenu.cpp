#include "../../include/observadores/ObservadorMenu.h"
#include "../../include/gerenciadores/Gerenciador_Eventos.h"

namespace Observadores
{
    ObservadorMenu::ObservadorMenu(Estados::Menus::Menu* pM):
    Observador(Gerenciadores::Gerenciador_Eventos::getInstancia()),
    pMenu(pM)
    {
    }

    ObservadorMenu::~ObservadorMenu()
    {
    }

    void ObservadorMenu::teclaPressionada(const sf::Keyboard::Key tecla)
    {
        if(tecladoEspecial[tecla] == "Up")
        {
            pMenu->irPraCima();
        }
        else if(tecladoEspecial[tecla] == "Down")
        {
            pMenu->irPraBaixo();
        }
        else if(tecladoEspecial[tecla] == "Enter")
        {
            pMenu->selecionar();
        }
    }

    void ObservadorMenu::teclaSolta(const sf::Keyboard::Key tecla)
    {
        if(tecladoEspecial[tecla] == "Up" || tecladoEspecial[tecla] == "Down")
        {
            pMenu->podeMoverBotao();
        }
        else if(tecladoEspecial[tecla] == "Enter")
        {
            pMenu->podeSelecionarBotao();
        }
    }
}