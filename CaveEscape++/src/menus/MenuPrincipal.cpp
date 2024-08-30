#include "../../include/menus/MenuPrincipal.h"
#include "Ente.h"
#include "SFML/Graphics/Color.hpp"
#include "texto/ElementoTexto.h"

namespace Menus
{
    MenuPrincipal::MenuPrincipal(): Menu(MenuId, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Texto::ElementoTexto("CaveEscape++"))
    {
        //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.

        nome.setPosicao(sf::Vector2f(tamanhoJanela.x / 2.0f - nome.getTamanho().x / 2.0f, 25.0f));
        nome.setCor(sf::Color::White);

    }

    MenuPrincipal::~MenuPrincipal()
    {
        
    }

    void MenuPrincipal::criarBotoes()
    {

        const float posicaoBotaoX = tamanhoJanela.x / 2.0f - tamanhoBotao.x / 2.0f;
        adicionarBotao("Novo Jogo", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f), sf::Color::White, Botao);
        adicionarBotao("Carregar Jogo", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f + tamanhoBotao.y * 1.0f), sf::Color::White, Botao);
        adicionarBotao("Colocacao", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f + tamanhoBotao.y * 2.0f), sf::Color::White, Botao);
        adicionarBotao("Opcao", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f + tamanhoBotao.y * 3.0f), sf::Color::White, Botao);
        adicionarBotao("Sair", sf::Vector2f(posicaoBotaoX, tamanhoJanela.y / 2.0f + tamanhoBotao.y * 4.0f), sf::Color::White, Botao);
    }
    void MenuPrincipal::executar()
    {

        pGGrafico->limparJanela();

        desenhar(pGGrafico->getJanela());

        pGGrafico->mostrarJanela();

    }

}