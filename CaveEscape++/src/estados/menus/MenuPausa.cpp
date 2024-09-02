#include "../../../include/estados/menus/MenuPausa.h"
#include "../../../include/texto/ElementoTexto.h"
#include "SFML/Graphics/Color.hpp"

namespace Estados
{
    namespace Menus
    {
        idEstados MenuPausa::fasePausada(idEstados::Indefinido);

        MenuPausa::MenuPausa(Estados::Fases::Fase* pFase): 
        Menu(idEstados::Pause, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y))
        {
            //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
            criarBotoes();
            nome = new Texto::ElementoTexto(100, 0, 0, sf::Color::White, "assets/fonts/StepalangeShort.ttf");
            nome->setString("Jogo pausado");
            nome->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome->getTamanho().x / 2.0f, 100.0f));
            podeSelecionarBotao();
        }

        MenuPausa::~MenuPausa()
        {
            fasePausada = idEstados::Indefinido;
        }

        void MenuPausa::setFase(idEstados faseEscolhida)
        {
            fasePausada = faseEscolhida;
        }
        
        idEstados MenuPausa::getFase()
        {
            return fasePausada;
        }

        void MenuPausa::selecionar()
        {
            if(selecionarBotao)
            {
                std::string selecao = (*it)->getTexto();
                if(selecao == "Voltar ao Jogo")
                {
                    modificarEstado(fasePausada);
                }
                else if(selecao == "Menu Principal")
                {
                    modificarEstado(idEstados::Principal);
                }
            }
            selecionarBotao = false;
        }

        void MenuPausa::criarBotoes()
        {
            const float posicaoBotaoX = tamanhoJanela.x / 2.0f - tamanhoBotao.x / 2.0f;
            adicionarBotao("Voltar ao Jogo", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f), sf::Color::White, Botao);
            adicionarBotao("Salvar Jogada", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f + (50 + tamanhoBotao.y) * 1.0f), sf::Color::White, Botao);
            adicionarBotao("Menu Principal", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f + (50 + tamanhoBotao.y) * 2.0f), sf::Color::White, Botao);
            it = listaBotoes.begin();
        }
    }
}