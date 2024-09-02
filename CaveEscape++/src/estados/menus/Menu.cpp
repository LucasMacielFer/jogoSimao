#include "../../../include/estados/menus/Menu.h"
#include "../../../include/observadores/ObservadorMenu.h"
#include "Ente.h"
#include "SFML/Graphics/Color.hpp"
#include "texto/ElementoBotao.h"
#include "texto/ElementoTexto.h"

namespace Estados
{
    namespace Menus
    {
        Menu::Menu(const idEstados ide, const sf::Vector2f tamBotao): 
        Ente(idEntes::MenuId), 
        Estado(ide),
        listaBotoes(), 
        it(NULL), 
        nome(NULL),
        tamanhoBotao(tamBotao), 
        tamanhoJanela(pGGrafico->getTamJanela()), 
        moverBotao(true),
        selecionarBotao(false),
        pObs(new Observadores::ObservadorMenu(this))
        {
        }

        Menu::~Menu()
        {
            if(!listaBotoes.empty())
            {
                for(it = listaBotoes.begin(); it != listaBotoes.end(); it++)
                {
                    if(*it)
                    {
                        delete (*it);
                        (*it) = NULL;
                    }
                }
            }
        }

        void Menu::adicionarBotao(const char* txt, const sf::Vector2f posicaoBotao, const sf::Color corBotao, const idEntes Id)
        {
            Texto::ElementoBotao* BotaoAdicionado = new Texto::ElementoBotao(posicaoBotao, tamanhoBotao, txt, Id, corBotao);
            listaBotoes.push_back(BotaoAdicionado);
        }

        //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
        void Menu::irPraCima()
        {
            if(moverBotao)
            {
                Texto::ElementoBotao* botao = *it;
                botao->setPressionado(false);

                if(it == listaBotoes.begin())
                {
                    it = listaBotoes.end();
                }

                it--;
                botao = *it;
                botao->setPressionado(true);
                moverBotao = false;
                selecionarBotao = true;
            }
        }

        //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
        void Menu::irPraBaixo()
        {
            if(moverBotao)
            {
                Texto::ElementoBotao* botao = *it;
                botao->setPressionado(false);
                it++;

                if(it == listaBotoes.end())
                {
                    it = listaBotoes.begin();
                }
                botao = *it;
                botao->setPressionado(true);
                moverBotao = false;
                selecionarBotao = true;
            }
        }

        void Menu::podeMoverBotao()
        {
            moverBotao = true;
        }

        void Menu::podeSelecionarBotao()
        {
            selecionarBotao = true;
        }

        void Menu::desenhar(sf::RenderWindow& janela)
        {
            std::list <Texto::ElementoBotao*>::iterator pBotao;
            Texto::ElementoBotao* botao = NULL;
            
            for(pBotao = listaBotoes.begin(); pBotao != listaBotoes.end(); pBotao++)
            {
                botao = (*pBotao);

                if(botao)
                {
                    botao->desenhar(janela);
                    botao = NULL;
                }
            }

            nome->desenhar(janela);
        }

        void Menu::executar(float dt)
        {
            std::list<Texto::ElementoBotao*>::iterator itr;
            for(itr = listaBotoes.begin(); itr != listaBotoes.end(); itr++)
            {
                (*itr)->executar(dt);
            }
        }

        void Menu::setAtivo(const bool at)
        {
            ativo = at;
            pObs->setAtivo(at);
            selecionarBotao = false;
        }
    }
}