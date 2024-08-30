#pragma once

#include "../Ente.h"
#include "../texto/ElementoBotao.h"
#include "SFML/System/Vector2.hpp"
#include <list>

#define TAMANHO_BOTAO_X 300.0f
#define TAMANHO_BOTAO_Y 40.0f

namespace Menus
{
    class Menu: public Ente
    {
        protected:

        std::list<Texto::ElementoBotao*> listaBotoes;
        std::list<Texto::ElementoBotao*>::iterator it;
        const sf::Vector2f tamanhoBotao;
        const sf::Vector2f tamanhoJanela;
        Texto::ElementoTexto nome;
        bool mousePressionado;

        public:

        Menu(const idEntes id, const sf::Vector2f tamBotao, const std::string txt);
        virtual ~Menu();

        void adicionarBotao(const std::string txt, const sf::Vector2f posicaoBotao, const sf::Color corBotao, const idEntes Id);
        void irPraCima();
        void irPraBaixo();
        void acaoMouse(const sf::Vector2f posicaoMouse);
        const bool getMousePressionado() const;
        virtual void executar() = 0;
        void desenhar(sf::RenderWindow& janela);

    };

}