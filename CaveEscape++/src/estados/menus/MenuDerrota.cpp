#include "../../../include/estados/menus/MenuDerrota.h"
#include "../../../include/estados/GerenciadorEstados.h"
#include "../../../include/texto/ElementoTexto.h"
#include "SFML/Graphics/Color.hpp"

namespace Estados
{
    namespace Menus
    {
        MenuDerrota::MenuDerrota(): 
        Menu(idEstados::Derrota, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)),
        pontuacaoDerrota(NULL)
        {
            //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
            criarBotoes();
            nome = new Texto::ElementoTexto(100, 0, 0, sf::Color::Red, "assets/fonts/StepalangeShort.ttf");
            nome->setString("VOCE MORREU!");
            nome->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome->getTamanho().x / 2.0f, 100.0f));
            pontuacaoDerrota = new Texto::ElementoTexto(70, 0, 0, sf::Color::Red, "assets/fonts/StepalangeShort.ttf");
            pontuacaoDerrota->setString("Pontuacao: " + std::to_string(pontJ1+pontJ2));
            pontuacaoDerrota->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - pontuacaoDerrota->getTamanho().x / 2.0f, 200.0f));
            podeSelecionarBotao();
        }

        MenuDerrota::~MenuDerrota()
        {
        }

        void MenuDerrota::selecionar()
        {
            if(selecionarBotao)
            {
                std::string selecao = (*it)->getTexto();
                if(selecao == "Menu Principal")
                {
                    modificarEstado(idEstados::Principal);
                }
            }
            selecionarBotao = false;
        }

        void MenuDerrota::criarBotoes()
        {
            const float posicaoBotaoX = tamanhoJanela.x / 2.0f - tamanhoBotao.x / 2.0f;
            adicionarBotao("Menu Principal", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 4.0f), sf::Color::White, Botao);
            it = listaBotoes.begin();
        }

        void MenuDerrota::desenhar(sf::RenderWindow& janela)
        {
            Menu::desenhar(janela);
            pontuacaoDerrota->desenhar(janela);
        }
    }
}