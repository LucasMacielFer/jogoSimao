#include "../../../include/estados/menus/MenuPrincipal.h"
#include "../../../include/estados/GerenciadorEstados.h"
#include "../../../include/texto/ElementoTexto.h"
#include "SFML/Graphics/Color.hpp"

namespace Estados
{
    namespace Menus
    {
        MenuPrincipal::MenuPrincipal(): 
        Menu(idEstados::Principal, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)),
        saida(false)
        {
            //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
            criarBotoes();
            nome = new Texto::ElementoTexto(100, 0, 0, sf::Color::White, "assets/fonts/StepalangeShort.ttf");
            nome->setString("CaveEscape++");
            nome->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome->getTamanho().x / 2.0f, 100.0f));
            podeSelecionarBotao();

            pontJ1 = 0;
            pontJ2 = 0;
        }

        MenuPrincipal::~MenuPrincipal()
        {
        }

        void MenuPrincipal::selecionar()
        {
            if(selecionarBotao)
            {
                std::string selecao = (*it)->getTexto();
                if(selecao == "1 jogador")
                {
                    pGEstados->setNumJogs(1);
                    modificarEstado(idEstados::SelecaoFase);
                }
                else if(selecao == "2 jogadores")
                {
                    pGEstados->setNumJogs(2);
                    modificarEstado(idEstados::SelecaoFase);
                }
                else if(selecao == "Colocacao")
                {
                    modificarEstado(idEstados::TabelaLideres);
                }
                else if(selecao == "Sair")
                {
                    saida = true;
                    exit(1);
                }
            }
            selecionarBotao = false;
        }

        void MenuPrincipal::criarBotoes()
        {
            const float posicaoBotaoX = tamanhoJanela.x / 2.0f - tamanhoBotao.x / 2.0f;
            adicionarBotao("1 jogador", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100)), sf::Color::White, Botao);
            adicionarBotao("2 jogadores", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 1.0f), sf::Color::White, Botao);
            adicionarBotao("Carregar Jogo", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 2.0f), sf::Color::White, Botao);
            adicionarBotao("Colocacao", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 3.0f), sf::Color::White, Botao);
            adicionarBotao("Sair", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 4.0f), sf::Color::White, Botao);
            it = listaBotoes.begin();
        }
    }
}