#pragma once

#include "../../Ente.h"
#include "../../texto/ElementoBotao.h"
#include "../../texto/ElementoTexto.h"
#include "../Estado.h"
#include "SFML/System/Vector2.hpp"
#include <list>

#define TAMANHO_BOTAO_X 300.0f
#define TAMANHO_BOTAO_Y 40.0f

namespace Observadores
{
    class ObservadorMenu;
}

namespace Estados
{
    namespace Menus
    {
        class Menu: public Ente, public Estado
        {
            private:
                Observadores::ObservadorMenu* pObs;

            protected:
                std::list<Texto::ElementoBotao*> listaBotoes;
                std::list<Texto::ElementoBotao*>::iterator it;
                const sf::Vector2f tamanhoBotao;
                const sf::Vector2f tamanhoJanela;
                Texto::ElementoTexto* nome;
                bool moverBotao;
                bool selecionarBotao;

            public:
                Menu(const idEstados ide, const sf::Vector2f tamBotao);
                virtual ~Menu();

                void adicionarBotao(const char* txt, const sf::Vector2f posicaoBotao, const sf::Color corBotao, const idEntes Id);
                void irPraCima();
                void irPraBaixo();
                void podeMoverBotao();
                void podeSelecionarBotao();
                void desenhar(sf::RenderWindow& janela);
                void executar(float dt);
                void setAtivo(const bool at);
                virtual void selecionar() = 0;
                virtual void criarBotoes() = 0;
        };
    }
}