#pragma once

#include <SFML/Graphics.hpp>

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
            void desenhar(sf::RenderWindow& janela);
    };
}