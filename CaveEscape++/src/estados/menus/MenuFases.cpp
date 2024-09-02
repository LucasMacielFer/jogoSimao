#include "../../../include/estados/menus/MenuFases.h"

namespace Estados
{
    namespace Menus
    {
        MenuFases::MenuFases(): 
        Menu(idEstados::SelecaoFase, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)),
        numJogs(0)
        {
            //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
            criarBotoes();
            nome = new Texto::ElementoTexto(100, 0, 0, sf::Color::White, "assets/fonts/StepalangeShort.ttf");
            nome->setString("CaveEscape++");
            nome->setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome->getTamanho().x / 2.0f, 100.0f));
        }

        MenuFases::~MenuFases()
        {
        }

        void MenuFases::selecionar()
        {
            if(selecionarBotao)
            {
                std::string selecao = (*it)->getTexto();
                if(selecao == "Fase 1")
                {
                    modificarEstado(idEstados::Jogando1);
                }
                else if(selecao == "Fase 2")
                {
                    modificarEstado(idEstados::Jogando2);
                }
                else if(selecao == "Voltar")
                {
                    modificarEstado(idEstados::Principal);
                }
            }
            selecionarBotao = false;
        }

        void MenuFases::criarBotoes()
        {
            const float posicaoBotaoX = tamanhoJanela.x / 2.0f - tamanhoBotao.x / 2.0f;
            adicionarBotao("Fase 1", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100)), sf::Color::White, Botao);
            adicionarBotao("Fase 2", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 1.0f), sf::Color::White, Botao);
            adicionarBotao("Voltar", sf::Vector2f(posicaoBotaoX, (tamanhoJanela.y / 2.0f - 100) + (50 + tamanhoBotao.y) * 2.0f), sf::Color::White, Botao);
            it = listaBotoes.begin();
        }
    }
}