#include "../../include/menus/Menu.h"
#include "Ente.h"
#include "SFML/Graphics/Color.hpp"
#include "texto/ElementoBotao.h"

namespace Menus
{
    Menu::Menu(const idEntes id, const sf::Vector2f tamBotao, const std::string txt): Ente(MenuId), listaBotoes(), it(NULL), tamanhoBotao(tamBotao), tamanhoJanela(pGGrafico->getTamJanela()), /*nome()*/mousePressionado(false)
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

    void Menu::adicionarBotao(const std::string txt, const sf::Vector2f posicaoBotao, const sf::Color corBotao, const idEntes Id)
    {
        Texto::ElementoBotao* BotaoAdicionado = new Texto::ElementoBotao(posicaoBotao, tamanhoBotao, txt, Id, corBotao);
        listaBotoes.push_back(BotaoAdicionado);
    }
    //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
    void Menu::irPraCima()
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
    }

    //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
    void Menu::irPraBaixo()
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

    }
    void Menu::acaoMouse(const sf::Vector2f posicaoMouse) //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
    {
        std::list<Texto::ElementoBotao*>::iterator aux;
        mousePressionado = false;
        for(aux = listaBotoes.begin(); aux != listaBotoes.end(); aux++)
        {
            Texto::ElementoBotao* botao = *aux;
            sf::Vector2f posicaoBotao = botao->getPosicao();
            sf::Vector2f posicaoCamera = pGGrafico->getCamera().getCenter();
            if(posicaoMouse.x + posicaoCamera.x - tamanhoJanela.x / 2.0f > posicaoBotao.x && posicaoMouse.x + posicaoCamera.x - tamanhoJanela.x / 2.0f < posicaoBotao.x + tamanhoBotao.x && posicaoMouse.y + posicaoCamera.y - tamanhoJanela.y / 2.0f > posicaoBotao.y && posicaoMouse.y + posicaoCamera.y - tamanhoJanela.y / 2.0f < posicaoBotao.y + tamanhoBotao.y)
               {
                    (*it)->setPressionado(false);
                    it = aux;
                    (*it)->setPressionado(true);
                    mousePressionado = true;
                    break;
               }
        }


    }

    const bool Menu::getMousePressionado() const
    {
        return mousePressionado;
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
    }

}