#include "../../../include/estados/menus/MenuLideres.h"
#include "../../../include/estados/GerenciadorEstados.h"
#include "../../../include/texto/ElementoTexto.h"
#include "SFML/Graphics/Color.hpp"

namespace Estados
{
    namespace Menus
    {
        MenuLideres::MenuLideres(): 
        Menu(idEstados::TabelaLideres, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)),
        mapaLideres()
        {
            //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
            criarBotoes();
            nome = new Texto::ElementoTexto(100, 0, 0, sf::Color::White, "assets/fonts/StepalangeShort.ttf");
            nome->setString("Lideres");
            nome->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome->getTamanho().x / 2.0f, 100.0f));
            podeSelecionarBotao();
            criarTabela(CAMINHO_TABELA);
        }

        MenuLideres::~MenuLideres()
        {
        }

        void MenuLideres::selecionar()
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

        void MenuLideres::criarBotoes()
        {
            const float posicaoBotaoX = tamanhoJanela.x / 2.0f - tamanhoBotao.x / 2.0f;
            adicionarBotao("Menu Principal", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 4.0f), sf::Color::White, Botao);
            it = listaBotoes.begin();
        }

        void MenuLideres::criarTabela(const char* caminhoSalvamento)
        {
            std::string pont;
            std::string jog;
            std::ifstream leitor(caminhoSalvamento, std::ios::in);;
            std::multimap<int, std::string> mapaArquivo;

            while(leitor >> pont >> jog)
            {
                mapaArquivo.insert(std::make_pair(std::stoi(pont), (jog + ": " + pont)));
            }

            leitor.close();

            Texto::ElementoTexto* colocacao;
            std::multimap<int, std::string>::reverse_iterator it;
            int i = 0;
            for(it = mapaArquivo.rbegin(); it != mapaArquivo.rend() && i<10; it++)
            {
                colocacao = new Texto::ElementoTexto(50, 0, 0, sf::Color::White, "assets/fonts/StepalangeShort.ttf");
                colocacao->setString((*it).second);
                colocacao->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome->getTamanho().x / 2.0f, 200.0f + (50*i)));
                mapaLideres.insert(std::make_pair((*it).first, colocacao));
                colocacao = NULL;
                i++;
            }
        }

        void MenuLideres::desenhar(sf::RenderWindow& janela)
        {
            Menu::desenhar(janela);
            std::multimap<int, Texto::ElementoTexto*>::reverse_iterator it;
            for(it = mapaLideres.rbegin(); it != mapaLideres.rend(); it++)
            {
                ((*it).second)->desenhar(janela);
            }
        }
    }
}