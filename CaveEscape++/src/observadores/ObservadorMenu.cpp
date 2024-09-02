#include "../../include/observadores/ObservadorMenu.h"
#include "../../include/gerenciadores/GerenciadorEventos.h"

namespace Observadores
{
    ObservadorMenu::ObservadorMenu(Estados::Menus::Menu* pM):
    Observador(Gerenciadores::GerenciadorEventos::getInstancia()),
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
            pMenu->podeSelecionarBotao();
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
            pMenu->selecionar();
        }

        if(pMenu->getIdentificador() == Estados::idEstados::SalvarNome)
        {
            Estados::Menus::MenuSalvar* pSalvar = dynamic_cast<Estados::Menus::MenuSalvar*>(pMenu);
            if(teclado[tecla] >= 'a' && teclado[tecla] <= 'z')
            {
                pSalvar->digitar(teclado[tecla]);
            }

            if(tecladoEspecial[tecla] == "BackSpace")
            {
                pSalvar->deletar();
            }
        }
    }
}