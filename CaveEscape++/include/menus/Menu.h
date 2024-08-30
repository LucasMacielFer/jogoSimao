#pragma once

#include "../Ente.h"
#include "../texto/ElementoBotao.h"
#include "SFML/System/Vector2.hpp"
#include <list>

namespace Menus
{
    class Menu: public Ente
    {
        protected:

        //std::list<Texto::ElementoBotao*> listaBotoes;
        //std::list<Texto::ElementoBotao*>::iterator it;
        const sf::Vector2f tamanhoBotao;
        const sf::Vector2f tamanhoJanela;
        Texto::ElementoTexto nome;
        bool mousePressionado;

        public:

        Menu(const idEntes id, const sf::Vector2f tamBotao, const std::string txt);
        ~Menu();

        void adicionarBotao(Texto::ElementoBotao*);
        void irPraCima();
        void irPraBaixo();
        void acaoMouse(const sf::Vector2f posicaoMouse);
        const bool getMousePressionado() const;
        virtual void executar();
        void desenhar();

    };

}