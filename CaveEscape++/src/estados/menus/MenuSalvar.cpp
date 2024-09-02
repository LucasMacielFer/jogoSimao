#include "../../../include/estados/menus/MenuSalvar.h"
#include "../../../include/estados/GerenciadorEstados.h"
#include "../../../include/texto/ElementoTexto.h"
#include "SFML/Graphics/Color.hpp"

namespace Estados
{
    namespace Menus
    {
        MenuSalvar::MenuSalvar(): 
        Menu(idEstados::SalvarNome, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)),
        nomeJogador(NULL)
        {
            //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
            criarBotoes();
            nome = new Texto::ElementoTexto(100, 0, 0, sf::Color::White, "assets/fonts/StepalangeShort.ttf");
            nome->setString("Digite seu nome:");
            nome->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome->getTamanho().x / 2.0f, 100.0f));
            nomeJogador = new Texto::ElementoTexto(70, 0, 0, sf::Color::White, "assets/fonts/StepalangeShort.ttf");
            nomeJogador->setString("");
            nomeJogador->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nomeJogador->getTamanho().x / 2.0f, 270.0f));
            podeSelecionarBotao();
        }

        MenuSalvar::~MenuSalvar()
        {
        }

        void MenuSalvar::selecionar()
        {
            if(selecionarBotao)
            {
                std::string selecao = (*it)->getTexto();
                if(selecao == "Salvar")
                {
                    salvar("assets/salvamento/lideres.txt");
                    modificarEstado(idEstados::Principal);
                }
                else if(selecao == "Menu Principal")
                {
                    modificarEstado(idEstados::Principal);
                }
            }
            selecionarBotao = false;
        }

        void MenuSalvar::criarBotoes()
        {
            const float posicaoBotaoX = tamanhoJanela.x / 2.0f - tamanhoBotao.x / 2.0f;
            adicionarBotao("Salvar", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 3.0f), sf::Color::White, Botao);
            adicionarBotao("Menu Principal", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 4.0f), sf::Color::White, Botao);
            it = listaBotoes.begin();
        }

        void MenuSalvar::digitar(char c)
        {
            nomeJogador->operator+=(c);
            nomeJogador->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nomeJogador->getTamanho().x / 2.0f, 270.0f));
        }

        void MenuSalvar::deletar()
        {
            nomeJogador->operator--();
            nomeJogador->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nomeJogador->getTamanho().x / 2.0f, 270.0f));
        }

        void MenuSalvar::desenhar(sf::RenderWindow& janela)
        {
            nomeJogador->desenhar(janela);
            Menu::desenhar(janela);
        }

        void MenuSalvar::salvar(const char* caminhoSalvamento)
        {
            std::ofstream gravador(caminhoSalvamento, std::ios::app);
            if(!gravador)
            {
                std::cout<<"Erro ao salvar recorde"<<std::endl;
            }
            else
            {
                gravador << std::to_string(pontJ1 + pontJ2) << " " << nomeJogador->getString() << std::endl;
            }
            gravador.close();
        }
    }
}