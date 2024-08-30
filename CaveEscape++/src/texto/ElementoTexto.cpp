#include "../../include/texto/ElementoTexto.h"
#include <iostream>

namespace Texto
{
    ElementoTexto::ElementoTexto(const int tam, const float x, const float y, sf::Color cor, const char* caminhoFonte):
    fonte(),
    texto()
    {
        if(!fonte.loadFromFile(caminhoFonte))
        {
            std::cout<<"Falha ao carregar fonte"<<std::endl;
            exit(1);
        }
        texto.setFont(fonte);
        texto.setColor(cor);
        texto.setPosition(x, y);
        texto.setCharacterSize(tam);
        texto.setString("");
    }

    ElementoTexto::ElementoTexto():
    fonte(),
    texto()
    {
    }

    ElementoTexto::~ElementoTexto()
    {
        texto.setString("");
    }

    void ElementoTexto::setString(std::string str)
    {
        texto.setString(str);
    }

    void ElementoTexto::setCor(sf::Color cor)
    {
        texto.setColor(cor);
    }

    void ElementoTexto::setX(const float x)
    {
        float y = texto.getPosition().y;
        texto.setPosition(x, y);
    }

    const sf::Vector2f ElementoTexto::getTamanho() const
    {
        return texto.getScale();
    }
    void ElementoTexto::setPosicao(sf::Vector2f posTexto)
    {
        texto.setPosition(posTexto);
    }

    void ElementoTexto::desenhar(sf::RenderWindow& janela)
    {
        janela.draw(texto);
    }
}