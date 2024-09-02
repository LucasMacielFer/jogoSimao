#include "../../../include/estados/menus/MenuPausa.h"
#include "Ente.h"
#include "SFML/Graphics/Color.hpp"
#include "texto/ElementoTexto.h"

namespace Estados
{
    namespace Menus
    {
        MenuPausa::MenuPausa(Estados::Fases::Fase* pFase): 
        Menu(idEstados::Pause, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y))
        {
            //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.

            //nome.setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome.getTamanho().x / 2.0f, 25.0f));
            //nome.setCor(sf::Color::White);

        }

        MenuPausa::~MenuPausa()
        {
            faseApontada = NULL;
        }

        void MenuPausa::setFase(Estados::Fases::Fase* faseEscolhida)
        {
            faseApontada = faseEscolhida;
        }
        
        Estados::Fases::Fase* MenuPausa::getFase()
        {
            return faseApontada;
        }

        void MenuPausa::selecionar()
        {
            if(selecionarBotao)
            {
                
            }
            selecionarBotao = false;
        }

        void MenuPausa::criarBotoes()
        {
            const float posicaoBotaoX = tamanhoJanela.x / 2.0f - tamanhoBotao.x / 2.0f;
            adicionarBotao("Voltar ao Jogo", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f), sf::Color::White, Botao);
            adicionarBotao("Salvar Jogada", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f + tamanhoBotao.y * 1.0f), sf::Color::White, Botao);
            adicionarBotao("Sair", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f + tamanhoBotao.y * 2.0f), sf::Color::White, Botao);
        }
    }
}