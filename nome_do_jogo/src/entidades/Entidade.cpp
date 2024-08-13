#include "../../include/entidades/Entidade.h"

namespace Entidades
{
    Entidade::Entidade(const int tamXX, const int tamYY, const int xx, const int yy):
    Ente(),
    tamX(tamXX),
    tamY(tamYY),
    x(xx),
    y(yy),
    retangulo(sf::Vector2f(100, 100))
    {
        retangulo.setOrigin(tamX / 2, tamY / 2);
        retangulo.setPosition(x, y);
        retangulo.setFillColor(sf::Color::White);
    }

    Entidade::~Entidade()
    {
        x = -1;
        y = -1;
    }

    void Entidade::setTamanho(const int xx, const int yy)
    {
        tamX = xx;
        tamY = yy;
    }

    const int* Entidade::getTamanho() const
    {
        int v[2] = {tamX, tamY};
        return v;
    }

    void Entidade::setPosicao(const int xx, const int yy)
    {
        x = xx;
        y = yy;
    }

    const int* Entidade::getPosicao() const 
    {
        int v[2] = {x, y};
        return v;
    }

    void Entidade::desenhar(sf::RenderWindow& janela)
    {
        janela.draw(retangulo);
    }

    void Entidade::atualizaEntidade()
    {
        retangulo.setPosition(x, y);
    }
}