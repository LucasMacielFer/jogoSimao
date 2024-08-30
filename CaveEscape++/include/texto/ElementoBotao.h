#pragma once

#include "../Ente.h"
#include "ElementoTexto.h"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

//#define CAMINHO_FONTE ""

namespace Texto
{
    class ElementoBotao : public Ente
    {
        protected:

            sf::RectangleShape caixaTexto;
            ElementoTexto texto;
            sf::Vector2f posicao;
            sf::Vector2f tamanho;
            sf::Color cor;
            bool pressionado;

        public:

            ElementoBotao(const sf::Vector2f pos, const sf::Vector2f tam, const std::string txt, const idEntes Id, const sf::Color color);
            ~ElementoBotao();
            void atualizarPos(const sf::Vector2f novaPos);
            const sf::Vector2f getPosicao() const;
            void desenhar(sf::RenderWindow& janela);
            void setPressionado(const bool pressao);
            const bool getPressionado() const;
            void executar(const float dt);

    };

}