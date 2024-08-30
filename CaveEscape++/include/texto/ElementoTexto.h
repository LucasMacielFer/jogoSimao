#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace Texto
{
    class ElementoTexto
    {
        private:
            sf::Text texto;
            sf::Font fonte;
        
        public:
            ElementoTexto(const int tam, const float x, const float y, sf::Color cor, const char* caminhoFonte);
            ElementoTexto();
            ~ElementoTexto();
            void setString(std::string str);
            void setCor(sf::Color cor);
            void setX(const float x);
            const sf::Vector2f getTamanho() const;
            void setPosicao(sf::Vector2f posTexto);
            void desenhar(sf::RenderWindow& janela);
    };
}