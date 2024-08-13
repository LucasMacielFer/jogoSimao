#pragma once

#include "../Ente.h"

namespace Entidades
{
    class Entidade : public Ente
    {
    protected:
        int tamX;
        int tamY;
        int x;
        int y;
    
    private:
        sf::RectangleShape retangulo;
    
    public:
        Entidade(const int tamXX=10, const int tamYY=10, const int xx=0, const int yy=0);
        virtual ~Entidade();
        void setTamanho(const int xx, const int yy);
        const int* getTamanho() const;
        void setPosicao(const int xx, const int yy);
        const int* getPosicao() const;
        void desenhar(sf::RenderWindow& janela);
        virtual void executar() = 0;
        virtual void salvar() = 0;

    protected:
        void atualizaEntidade();
    };
}