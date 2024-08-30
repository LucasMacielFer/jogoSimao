#include "../../include/texto/ElementoBotao.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
//#include "SFML/Graphics/Texture.hpp"
//#include "Ente.h"
//#include "SFML/System/Vector2.hpp"

namespace Texto
{

    ElementoBotao::ElementoBotao(const sf::Vector2f pos, const sf::Vector2f tam, const std::string txt, const idEntes Id, const sf::Color color): Ente(Botao), posicao(pos), tamanho(tam), cor(color), pressionado(false) 
    {
        caixaTexto.setPosition(pos);
        caixaTexto.setSize(tam);

        //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
        sf::Vector2f tamTexto = texto.getTamanho();
        sf::Vector2f posTexto = sf::Vector2f(pos.x + tam.x / 2.0f - tamTexto.x / 2.05f, pos.y + tam.y / 2.0f - tamTexto.y * 1.2f);

        texto.setPosicao(posTexto);
    }

    ElementoBotao::~ElementoBotao()
    {

    }

    void ElementoBotao::atualizarPos(sf::Vector2f novaPos) //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
    {
        this->posicao = novaPos;
        caixaTexto.setPosition(novaPos);

        sf::Vector2f tamTexto = texto.getTamanho();

        sf::Vector2f posTexto = sf::Vector2f( posicao.x + tamanho.x / 2.0f - tamTexto.x / 2.05f, posicao.y + tamanho.y / 2.0f - tamTexto.y * 1.2f);

        texto.setPosicao(posTexto);
    }

    const sf::Vector2f ElementoBotao:: getPosicao() const
    {
        return caixaTexto.getPosition();
    }

    void ElementoBotao::desenhar(sf::RenderWindow& janela)
    {
        janela.draw(caixaTexto);
    }

    void ElementoBotao::setPressionado(const bool pressao)
    {
        if(pressao)
            texto.setCor(sf::Color::Yellow);
        else
            texto.setCor(sf::Color::White);

        pressionado = pressao;
    }

    const bool ElementoBotao::getPressionado() const
    {
        return pressionado;
    }
}