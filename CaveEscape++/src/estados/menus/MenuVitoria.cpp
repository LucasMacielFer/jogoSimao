#include "../../../include/estados/menus/MenuVitoria.h"
#include "../../../include/estados/GerenciadorEstados.h"
#include "../../../include/texto/ElementoTexto.h"
#include "../../../include/estados/fases/Fase.h"
#include "SFML/Graphics/Color.hpp"

namespace Estados
{
    namespace Menus
    {
        MenuVitoria::MenuVitoria(): 
        Menu(idEstados::Vitoria, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)),
        pontuacaoVitoria(NULL)
        {
            //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
            criarBotoes();
            nome = new Texto::ElementoTexto(100, 0, 0, sf::Color::White, "assets/fonts/StepalangeShort.ttf");
            nome->setString("VOCE VENCEU!");
            nome->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome->getTamanho().x / 2.0f, 100.0f));
            pontuacaoVitoria = new Texto::ElementoTexto(70, 0, 0, sf::Color::White, "assets/fonts/StepalangeShort.ttf");
            pontuacaoVitoria->setString("Pontuacao: " + std::to_string(pontJ1+pontJ2));
            pontuacaoVitoria->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - pontuacaoVitoria->getTamanho().x / 2.0f, 200.0f));
            podeSelecionarBotao();
        }

        MenuVitoria::~MenuVitoria()
        {
        }

        void MenuVitoria::selecionar()
        {
            if(selecionarBotao)
            {
                std::string selecao = (*it)->getTexto();
                if(selecao == "Menu principal")
                {
                    modificarEstado(idEstados::Principal);
                }
                else if(selecao == "Salvar")
                {
                    modificarEstado(idEstados::SalvarNome);
                }
            }
            selecionarBotao = false;
        }

        void MenuVitoria::criarBotoes()
        {
            const float posicaoBotaoX = tamanhoJanela.x / 2.0f - tamanhoBotao.x / 2.0f;
            adicionarBotao("Salvar", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 3.0f), sf::Color::White, Botao);
            adicionarBotao("Menu principal", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 4.0f), sf::Color::White, Botao);
            it = listaBotoes.begin();
        }

        void MenuVitoria::desenhar(sf::RenderWindow& janela)
        {
            Menu::desenhar(janela);
            pontuacaoVitoria->desenhar(janela);
        }
    }
}