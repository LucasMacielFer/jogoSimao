#include "../../include/texto/ElementoBotao.h"
#include "texto/ElementoTexto.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Texto
{

    ElementoBotao::ElementoBotao(const sf::Vector2f pos, const sf::Vector2f tam, const char* txt, const idEntes Id, const sf::Color color): 
    Ente(Botao), 
    texto(40, 0, 0, sf::Color::Black, "assets/fonts/StepalangeShort.ttf"),
    posicao(pos), 
    tamanho(tam), 
    cor(color), 
    pressionado(false) 
    {
        caixaTexto.setPosition(pos);
        caixaTexto.setSize(tam);

        //Método adaptado do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
        texto.setString(txt);
        sf::Vector2f tamTexto = texto.getTamanho();
        sf::Vector2f posTexto = sf::Vector2f(pos.x + tam.x / 2.0f - tamTexto.x /2.0f, pos.y + tam.y / 2.0f - tamTexto.y);
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
        texto.desenhar(janela);
    }

    void ElementoBotao::setPressionado(const bool pressao)
    {
        pressionado = pressao;
    }

    const bool ElementoBotao::getPressionado() const
    {
        return pressionado;
    }

    std::string ElementoBotao::getTexto() const
    {
        return texto.getString();
    }

    void ElementoBotao::executar(float dt)
    {
        if(pressionado)
        {
            caixaTexto.setFillColor(sf::Color::Cyan);
        }
        else
        {
            caixaTexto.setFillColor(cor);
        }
    }
}