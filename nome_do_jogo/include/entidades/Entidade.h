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
        Entidade(const float tamXX=10.0f, const float tamYY=10.0f, const float xx=0.0f, const float yy=0.0f);
        virtual ~Entidade();
        void setTamanho(const float xx, const float yy);
        const sf::Vector2f getTamanho() const;
        void setPosicao(const float xx, const float yy);
        const sf::Vector2f getPosicao() const;
        void desenhar(sf::RenderWindow& janela);
        virtual void executar() = 0;
        virtual void salvar() = 0;

    protected:
        void atualizaEntidade();
    };
}