#pragma once

#include "../Ente.h"

namespace Entidades
{
    class Entidade : public Ente
    {
    protected:
        float tamX;
        float tamY;
        float x;
        float y;
    
    private:
        sf::RectangleShape retangulo;
    
    public:
        Entidade(const int i, sf::Color c, const float tamXX, const float tamYY, const float xx=0.0f, const float yy=0.0f);
        Entidade();
        virtual ~Entidade();
        void setTamanho(const float xx, const float yy);
        const sf::Vector2f getTamanho() const;
        void setPosicao(const float xx, const float yy);
        const sf::Vector2f getPosicao() const;
        void desenhar(sf::RenderWindow& janela);
        virtual void executar(float dt) = 0;
        virtual void salvar() = 0;

    protected:
        void atualizaEntidade();
    };
}